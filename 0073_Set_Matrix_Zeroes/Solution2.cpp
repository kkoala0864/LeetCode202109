#include <Solution.h>
#include <iostream>

void Solution::setZeroes2(vector<vector<int>> &matrix) {
	bool isCol = false;
	int m = matrix.size();
	int n = matrix[0].size();
	for (int i = 0; i < matrix.size(); ++i) {
		if (matrix[i][0] == 0) {
			isCol = true;
		}
		for (int j = 1; j < n; ++j) {
			if (matrix[i][j] == 0) {
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
		}
	}

	for (int i = 1; i < m; ++i) {
		for (int j = 1; j < n; ++j) {
			if (matrix[i][0] == 0 || matrix[0][j] == 0) {
				matrix[i][j] = 0;
			}
		}
	}

	if (matrix[0][0] == 0) {
		for (int j = 1; j < n; ++j) {
			matrix[0][j] = 0;
		}
	}

	if (isCol) {
		for (int i = 0; i < m; ++i) {
			matrix[i][0] = 0;
		}
	}
}
