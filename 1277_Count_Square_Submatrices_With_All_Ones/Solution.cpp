#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::min;

int Solution::countSquares(vector<vector<int>>& matrix) {

	int m = matrix.size();
	int n = matrix[0].size();

	vector<vector<int>> dp = vector<vector<int>>(m, vector<int>(n, 0));
	int result = 0;
	for (int i = 0 ; i < m ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			if (matrix[i][j] == 0) continue;
			if (i == 0 || j == 0) dp[i][j] = 1;
			else {
				dp[i][j] = min({dp[i-1][j-1], dp[i][j-1], dp[i-1][j]}) + 1;
			}
			result += dp[i][j];
		}
	}
	return result;
}
