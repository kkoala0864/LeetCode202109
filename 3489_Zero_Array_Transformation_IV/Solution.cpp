#include <Solution.h>
#include <iostream>
#include <unordered_set>
#include <algorithm>

using std::max;
using std::unordered_set;
using std::cout;
using std::endl;

int getK(vector<int>& preSum, int val) {
	vector<bool> dp(val + 1, false);
	dp[0] = true;

	for (int k = 0 ; k < preSum.size() ; ++k) {
		if (preSum[k] == 0) continue;
		for (int i = val ; i >= preSum[k] ; --i) {
			if (dp[i-preSum[k]]) dp[i] = true;
		}
		if (dp.back()) return k+1;
	}
	return -1;
}

int Solution::minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
	vector<vector<int>> preSum(nums.size(), vector<int>(queries.size(), 0));

	for (int i = 0 ; i < queries.size() ; ++i) {
		for (int j = queries[i][0] ; j <= queries[i][1] ; ++j) {
			preSum[j][i] += queries[i][2];
		}
	}

	int result = 0;
	for (int i = 0 ; i < nums.size() ; ++i) {
		if (nums[i] == 0) continue;
		int v = getK(preSum[i], nums[i]);
		if (v == -1) return -1;
		result = max(result, v);
	}
	return result;
}
