#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::min;

int Solution::minFallingPathSum(vector<vector<int>> &matrix) {
	vector<int> prev = matrix[0];
	vector<int> dp(matrix[0].size(), 0);

	for (int i = 1; i < matrix.size(); ++i) {
		for (int j = 0; j < matrix[0].size(); ++j) {
			int local = INT_MAX;
			if (j > 0) {
				local = min(prev[j - 1] + matrix[i][j], local);
			}
			local = min(prev[j] + matrix[i][j], local);
			if (j < matrix[0].size() - 1) {
				local = min(prev[j + 1] + matrix[i][j], local);
			}
			dp[j] = local;
		}
		swap(dp, prev);
	}
	int result = INT_MAX;
	for (int i = 0; i < prev.size(); ++i) {
		result = min(result, prev[i]);
	}
	return result;
}
