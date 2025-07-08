#include <Solution.h>

bool check(const vector<int>& sweetness, int k, int cap) {
	int cnt = 0;

	int cs = 0;
	for (const auto& v : sweetness) {
		cs += v;
		if (cs >= cap) {
			++cnt;
			cs = 0;
		}
	}
	return cnt >= k;
}

int Solution::maximizeSweetness(vector<int>& sweetness, int k) {
	int size = sweetness.size();
	int sum = 0;
	for (const auto& v : sweetness) sum += v;
	int l = 1 , r = sum;
	int mid = 0;

	while (l < r) {
		mid = l + ((r - l) >> 1);

		if (check(sweetness, k + 1, mid)) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	return l;
	/*
	vector<int> preSum(sweetness.size() + 1, 0);
	for (int i = 0 ; i < sweetness.size() ; ++i) {
		preSum[i+1] = preSum[i] + sweetness[i];
	}

	++k;
	int size = sweetness.size();
	vector<int> dp(size, 0);
	for (int i = 0 ; i < size ; ++i) {
		dp[i] = preSum[i+1];
	}
	for (int ki = 1 ; ki < k ; ++ki) {
		vector<int> next(size, 0);
		for (int r = ki ; r < size ; ++r) {
			for (int l = ki ; l <= r ; ++l) {
				next[r] = max(next[r], min(dp[l-1], preSum[r+1] - preSum[l]));
			}
		}
		dp = std::move(next);
	}
	return dp.back();
	*/
}
