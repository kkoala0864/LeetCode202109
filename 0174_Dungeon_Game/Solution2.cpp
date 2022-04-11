#include <Solution.h>
#include <iostream>
#include <climits>
#include <algorithm>

using std::min;

int Solution::calculateMinimumHP2(vector<vector<int>>& dungeon) {
	int m = dungeon.size(), n = dungeon[0].size();

	vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX));
	for (int i = m - 1 ; i >= 0 ; --i) {
		for(int j = n - 1 ; j >= 0 ; --j) {
			if (i == m-1 && j == n-1) dp[i][j] = dungeon[i][j] > 0 ? 1 : 1 - dungeon[i][j];
			else {
				int right = dungeon[i][j] >= dp[i][j+1] ? 1 : dp[i][j+1] == INT_MAX ? INT_MAX : dp[i][j+1] - dungeon[i][j];
				int down = dungeon[i][j] >= dp[i+1][j] ? 1 : dp[i+1][j] == INT_MAX ? INT_MAX : dp[i+1][j] - dungeon[i][j];
				dp[i][j] = min(right, down);
			}
		}
	}
	return dp[0][0];
}
