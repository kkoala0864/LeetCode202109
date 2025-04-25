#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;
using std::min;

int Solution::maximalSquare2(vector<vector<char>> &matrix) {
	int m = matrix.size(), n = matrix[0].size();
	vector<vector<int>> dp(m, vector<int>(n, 0));

	int result = 0;
	for (int i = 0; i < n; ++i)
		if (matrix[0][i] == '1')
			dp[0][i] = 1, result = 1;
	for (int i = 0; i < m; ++i)
		if (matrix[i][0] == '1')
			dp[i][0] = 1, result = 1;
	for (int i = 1; i < m; ++i) {
		for (int j = 1; j < n; ++j) {
			if (matrix[i][j] == '1') {
				dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
				result = max(result, dp[i][j]);
			}
		}
	}
	return result * result;
}
