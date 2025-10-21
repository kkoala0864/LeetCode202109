#include <Solution.h>

int Solution::maxFrequency(vector<int> &nums, int k, int numOperations) {
	int mxV = 0;
	for (const auto& v : nums) mxV = max(mxV, v);

	vector<int> cnt(mxV + k + 1, 0);

	for (const auto& v : nums) ++cnt[v];

	vector<int> preSum(cnt.size(), 0);
	for (int i = 1 ; i < cnt.size() ; ++i) {
		preSum[i] = preSum[i-1] + cnt[i];
	}

	int result = 0;
	for (int i = 0 ; i < cnt.size() ; ++i) {
		int l = max(0, i - k);
		int r = min(i + k, mxV + k);

		int convertable = preSum[r] - (l > 0 ? preSum[l-1] : 0) - cnt[i];

		result = max(result, cnt[i] + min(convertable, numOperations));
	}
	return result;
}
