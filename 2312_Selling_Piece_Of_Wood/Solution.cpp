#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using std::max;
using std::unordered_map;

long long Solution::sellingWood(int m, int n, vector<vector<int>>& prices) {
	vector<vector<long long>> dp(m+1, vector<long long>(n+1, 0));

	for (const auto& p : prices) dp[p[0]][p[1]] = p[2];

	for (int i = 1 ; i <= m ; ++i) {
		for (int j = 1 ; j <= n ; ++j) {
			for (int x = 1 ; x <= j/2 ; ++x) {
				dp[i][j] = max(dp[i][j], dp[i][x] + dp[i][j-x]);
			}
			for (int y = 1 ; y <= i/2 ; ++y) {
				dp[i][j] = max(dp[i][j], dp[y][j] + dp[i-y][j]);
			}
		}
	}
	return dp[m][n];
}

