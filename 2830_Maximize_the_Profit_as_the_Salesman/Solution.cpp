#include <Solution.h>

int Solution::maximizeTheProfit(int n, vector<vector<int>>& offers) {
	auto cmp = [](const vector<int>& lhs, const vector<int>& rhs) {
		return lhs[1] == rhs[1] ? lhs[0] < rhs[0] : lhs[1] < rhs[1];
	};

	sort(offers.begin(), offers.end(), cmp);

	vector<int> dp(n + 1, 0);
	int oi = 0;

	for (int i = 1 ; i <= n ; ++i) {
		dp[i] = dp[i-1];
		while (oi < offers.size() && offers[oi][1] < i) {
			dp[i] = max(dp[i], dp[offers[oi][0]] + offers[oi][2]);
			++oi;
		}
		if (oi == offers.size()) return dp[i];
	}
	return dp.back();
}
