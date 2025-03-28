#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::min;

vector<vector<int>> Solution::restoreMatrix(vector<int> &rowSum, vector<int> &colSum) {
	int m = rowSum.size(), n = colSum.size();

	vector<vector<int>> result = vector<vector<int>>(m, vector<int>(n, 0));

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			int v = min(rowSum[i], colSum[j]);
			result[i][j] += v;
			rowSum[i] -= v;
			colSum[j] -= v;
		}
	}
	return result;
}
