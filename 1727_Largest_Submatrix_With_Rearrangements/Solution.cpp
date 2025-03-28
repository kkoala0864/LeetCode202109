#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

int Solution::largestSubmatrix(vector<vector<int>> &matrix) {
	int n = matrix[0].size();
	int m = matrix.size();

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == 0 || matrix[i][j] == 0)
				continue;
			matrix[i][j] = matrix[i - 1][j] + 1;
		}
	}

	vector<int> tmp;
	int result = 0;
	for (int i = 0; i < m; ++i) {
		tmp = matrix[i];
		sort(tmp.begin(), tmp.end(), std::greater<int>());

		for (int j = 0; j < n; ++j) {
			result = max(result, tmp[j] * (j + 1));
		}
	}
	return result;
}
