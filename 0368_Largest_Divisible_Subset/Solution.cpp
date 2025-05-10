#include <Solution.h>

vector<int> Solution::largestDivisibleSubset(vector<int> &nums) {
	sort(nums.begin(), nums.end(), greater<>());

	vector<pair<int, int>> dp(nums.size(), pair<int, int>(1, -1));

	int maxLen = 0;
	int maxIdx = -1;
	for (int i = 0 ; i < nums.size() ; ++i) {
		for (int j = 0 ; j < i ; ++j) {
			if (nums[j] % nums[i]) continue;
			if (dp[j].first > dp[i].first) {
				dp[i].first = dp[j].first;
				dp[i].second = j;
			}
		}
		++dp[i].first;
		if (maxLen < dp[i].first) {
			maxLen = dp[i].first;
			maxIdx = i;
		}
	}

	vector<int> result;
	while (maxIdx != -1) {
		result.emplace_back(nums[maxIdx]);
		maxIdx = dp[maxIdx].second;
	}

	return result;
}
