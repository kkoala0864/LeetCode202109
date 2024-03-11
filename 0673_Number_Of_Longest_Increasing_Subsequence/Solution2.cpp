#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::pair;
using std::max;

int Solution::findNumberOfLIS2(vector<int>& nums) {
	vector<pair<int, int>> dp;

	int maxLen = 0;
	int result = 0;
	for (int i = 0 ; i < nums.size() ; ++i) {
		pair<int, int> cur(1, 1);
		for (int j = i - 1 ; j >= 0 ; --j) {
			if (nums[i] <= nums[j]) continue;
			if (dp[j].first + 1 > cur.first) {
				cur.first = dp[j].first + 1;
				cur.second = dp[j].second;
			} else if (dp[j].first + 1 == cur.first) {
				cur.second += dp[j].second;
			}
		}
		dp.emplace_back(cur);
		if (cur.first > maxLen) {
			maxLen = cur.first;
			result = cur.second;
		} else if (cur.first == maxLen) {
			result += cur.second;
		}
	}
	return result;
}
