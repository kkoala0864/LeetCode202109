#include <Solution.h>

long long getCost(long long l, long long r, vector<int>& nums, vector<long long>& preSum) {
	long long mid = (l + r) / 2;
	long long leftCost = nums[mid] * (mid - l) - (preSum[mid] - preSum[l]);
	long long rightCost = (preSum[r + 1] - preSum[mid+1]) - (nums[mid] * (r-mid));
	return leftCost + rightCost;
}

int Solution::maxFrequencyScore(vector<int>& nums, long long k) {
	sort(nums.begin(), nums.end());

	vector<long long> preSum(1, 0);
	for (int i = 0 ; i < nums.size() ; ++i) {
		preSum.emplace_back(preSum.back() + (long long)nums[i]);
	}
	int result = 0;
	int l = 0;
	for (int i = 0 ; i < nums.size() ; ++i) {
		while (l < i && getCost(l, i, nums, preSum) > k) {
			++l;
		}
		result = max(result, i - l + 1);
	}
	return result;
}
