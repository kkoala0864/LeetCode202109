#include <Solution.h>

int Solution::waysToSplit(vector<int>& nums) {
	int size = nums.size();
	vector<long long> preSum(1, nums[0]);
	long long result = 0;
	long long mod = 1e9 + 7;
	for (int i = 1 ; i < size ; ++i) {
		preSum.emplace_back(preSum.back() + nums[i]);
	}

	for (int i = 0 ; i < preSum.size() ; ++i) {
		if (preSum[i] > (preSum.back() / 3)) break;
		long long midLower = 2 * preSum[i];
		long long restOf = preSum.back() - preSum[i];
		long long midUpper = preSum[i] + (restOf / 2);
		long long ml = lower_bound(preSum.begin() + i + 1, preSum.end() - 1, midLower) - preSum.begin();
		if (ml == preSum.size() - 1) break;
		long long mu = upper_bound(preSum.begin() + i + 1 , preSum.end() - 1, midUpper) - preSum.begin();
		if (mu == i + 1) break;
		result += (mu - ml);
		result %= mod;
	}
	return result;
}
