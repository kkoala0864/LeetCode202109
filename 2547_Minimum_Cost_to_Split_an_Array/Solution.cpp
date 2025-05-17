#include <Solution.h>

// dp[i] = minCost split end with i
// dp[i] = min(dp[i], dp[i-1] + cost(i ~ j));
int Solution::minCost(vector<int>& nums, int k) {
	vector<int> dp(nums.size(), INT_MAX);

	unordered_map<int, int> initCnt;
	int iniUni = 0;
	for (int i = 0 ; i < nums.size() ; ++i) {
		++initCnt[nums[i]];
		if (initCnt[nums[i]] == 1) ++iniUni;
		else if (initCnt[nums[i]] == 2) --iniUni;
		dp[i] = k + i + 1 - iniUni;
	}

	for (int i = 1 ; i < nums.size() ; ++i) {
		unordered_map<int, int> cnt;
		int unique = 0;
		for (int j = i ; j > 0 ; --j) {
			++cnt[nums[j]];
			if (cnt[nums[j]] == 1) ++unique;
			else if (cnt[nums[j]] == 2) --unique;
			int curCost = k + (i - j + 1) - unique;
			dp[i] = min(dp[i], dp[j-1] + curCost);
		}
	}
	return dp.back();

}
