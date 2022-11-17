#include <Solution.h>
#include <iostream>

using std::pair;

// dp[i] = the longest size of subsequence end with i
// tc = O(n^2);
// sc = O(n);

int Solution::findNumberOfLIS(vector<int>& nums) {
	vector<pair<int, int>> dp;
	int maxLen = 1;
	int result = 1;

	dp.emplace_back(pair<int, int>(1, 1));

	for (int i = 1 ; i < nums.size() ; ++i) {
		int curLen = 1;
		int curCnt = 1;
		for (int j = 0 ; j < i ; ++j) {
			if (nums[i] <= nums[j]) continue;
			int len = dp[j].first + 1;
			if (len > curLen) {
				curLen = len;
				curCnt = dp[j].second;
			} else if (len == curLen) {
				curCnt += dp[j].second;
			}
		}
		dp.emplace_back(pair<int, int>(curLen, curCnt));
		if (maxLen < curLen) {
			maxLen = curLen;
			result = curCnt;
		} else if (maxLen == curLen) {
			result += curCnt;
		}
	}

	return result;
}
