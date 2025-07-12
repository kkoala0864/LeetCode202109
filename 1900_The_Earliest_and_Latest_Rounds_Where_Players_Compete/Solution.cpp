#include <Solution.h>

// pre condition
// if a > b return a < b;
//
// xxx a'xxxx b' xxxxxxxx M xxxxxxx a xxxx b xxxx
// (a + b) / 2 > (n+1) / 2 => return dp[a][b] = dp[n+1-b][n+1-a]
//
// in the middle
// xxxxx a xxxxx bb xxxx M xxxx b xxxxx aa xxxxx
//{  r1 } {  r2 }  {     z     }
// z = (b - bb - 1 + 1) / 2;
// dp[n][a][b] = dp[n / 2][r1 + 1][r1 + 1 + r2 + z + 1];

// in the left
// xxxxx a xxxxx b xxxxx M xxxxx bb xxxxx aa xxxxx
// dp[n][a][b] = dp[n/2][r1+1][r1 + 1 + r2 + 1];

vector<int> dfs(int n, int a, int b, vector<vector<vector<int>>>& dp1, vector<vector<vector<int>>>& dp2) {
	if ((a + b) == (n + 1)) return vector<int>({1,1});;
	if (dp1[n][a][b] != 0) {
		return vector<int>({dp1[n][a][b], dp2[n][a][b]});
	}

	if (a > b) return dfs(n, b, a, dp1, dp2);
	if (((a + b) / 2.0) > ((n + 1) / 2.0)) return dfs(n, n+1-b, n+1-a, dp1, dp2);

	int minVal = INT_MAX / 2;
	int maxVal = INT_MIN / 2;
	int bb = n + 1 - b;
	int z = (b - bb - 1 + 1) / 2;

	if (b > ((n + 1) / 2)) {
		for (int i = 0 ; i < a ; ++i) {
			for (int j = 0 ; j < (bb - a) ; ++j) {
				auto tmp = dfs((n + 1)/2, i + 1, i + 1 + j + z + 1, dp1, dp2);
				minVal = min(minVal, tmp[0] + 1);
				maxVal = max(maxVal, tmp[1] + 1);
			}
		}
	} else {
		for (int i = 0 ; i < a ; ++i) {
			for (int j = 0 ; j < (b - a) ; ++j) {
				auto tmp = dfs((n+1)/2, i + 1, i + 1 + j + 1, dp1, dp2);
				minVal = min(minVal, tmp[0] + 1);
				maxVal = max(maxVal, tmp[1] + 1);
			}
		}
	}
	dp1[n][a][b] = minVal;
	dp2[n][a][b] = maxVal;
	return vector<int>({minVal, maxVal});
}

vector<int> Solution::earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
	vector<vector<vector<int>>> dp1(30, vector<vector<int>>(30, vector<int>(30, 0)));
	vector<vector<vector<int>>> dp2(30, vector<vector<int>>(30, vector<int>(30, 0)));
	return dfs(n, firstPlayer, secondPlayer, dp1, dp2);
}
