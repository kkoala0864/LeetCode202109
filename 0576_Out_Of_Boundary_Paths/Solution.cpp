#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

int Solution::findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
	int mod = 1e9 + 7;
	vector<vector<int>> dp(m, vector<int>(n, 0));

	dp[startRow][startColumn] = 1;
	int cnt = 0;

	for (int i = 1 ; i <= maxMove ; ++i) {
		vector<vector<int>> tmp(m, vector<int>(n, 0));
		for (int x = 0 ; x < m ; ++x) {
			for (int y = 0 ; y < n ; ++y) {
				if (x == m-1) cnt = (cnt + dp[x][y]) % mod;
				if (y == n-1) cnt = (cnt + dp[x][y]) % mod;
				if (x == 0) cnt = (cnt + dp[x][y]) % mod;
				if (y == 0) cnt = (cnt + dp[x][y]) % mod;
				tmp[x][y] += x > 0 ? dp[x-1][y] % mod : 0;
				tmp[x][y] %= mod;
				tmp[x][y] += y > 0 ? dp[x][y-1] % mod : 0;
				tmp[x][y] %= mod;
				tmp[x][y] += x < m-1 ? dp[x+1][y] % mod : 0;
				tmp[x][y] %= mod;
				tmp[x][y] += y < n-1 ? dp[x][y+1] % mod : 0;
				tmp[x][y] %= mod;
			}
		}
		dp = move(tmp);
	}
	return cnt;
}
