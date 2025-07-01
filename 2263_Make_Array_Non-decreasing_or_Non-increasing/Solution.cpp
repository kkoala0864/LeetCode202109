#include <Solution.h>

int resolve(const vector<int>& nums) {
	int cost = 0;
	priority_queue<int> pq;

	for (const auto& v : nums) {
		if (!pq.empty() && pq.top() > v) {
			cost += (pq.top() - v);
			pq.pop();
			pq.emplace(v);
		}
		pq.emplace(v);
	}
	return cost;
}

int getCost(const vector<int>& nums) {
	const int maxV = 1000;
	vector<int> dpPrev(maxV + 1, 0), prefix(maxV + 1, 0), dpCur(maxV + 1, 0);

	for (int i = 0 ; i <= maxV ; ++i) {
		dpPrev[i] = abs(nums[0] - i);
	}

	for (int i = 1 ; i < nums.size() ; ++i) {
		prefix[0] = dpPrev[0];
		for (int j = 1 ; j <= maxV ; ++j) {
			prefix[j] = min(prefix[j-1], dpPrev[j]);
		}
		for (int j = 0 ; j <= maxV ; ++j) {
			dpCur[j] = prefix[j] + abs(nums[i] - j);
		}
		swap(dpPrev, dpCur);
	}
	int result = INT_MAX;
	for (const auto& v : dpPrev) result = min(result, v);
	return result;
}

int Solution::convertArray(vector<int>& nums) {
	int result = INT_MAX;
	result = min(result, getCost(nums));
	reverse(nums.begin(), nums.end());
	result = min(result, getCost(nums));
	return result;
}

