#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::max;
using std::pair;

long long dfs(int start, vector<int>& nums, int oper, vector<pair<long long, long long>>& dp) {
	if (start >= nums.size()) return 0;

	if (oper == 1 && dp[start].first != INT_MIN) {
		return dp[start].first;
	}
	if (oper == -1 && dp[start].second != INT_MIN) {
		return dp[start].second;
	}

	long long cur = nums[start] * oper;
	long long curMax = INT_MIN;
	if (oper == 1) {
		curMax = max(curMax, cur + dfs(start + 1, nums, -1, dp));
	}
	curMax = max(curMax, cur + dfs(start + 1, nums, 1, dp));

	if (oper == 1) {
		dp[start].first = curMax;
	} else {
		dp[start].second = curMax;
	}
	return curMax;
}

long long Solution::maximumTotalCost(vector<int>& nums) {
	vector<int> l;
	for (int i = 0 ; i < nums.size() ; ++i) {
		if (l.empty() || nums[i] != 0) l.emplace_back(nums[i]);
		else if (l.back() == 0) continue;
		else l.emplace_back(0);
	}
	vector<pair<long long, long long>> dp(l.size(), pair<long long, long long>(INT_MIN, INT_MIN));
	return dfs(0, l, 1, dp);
}
