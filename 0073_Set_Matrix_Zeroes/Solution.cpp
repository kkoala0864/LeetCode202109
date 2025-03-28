#include <Solution.h>
#include <iostream>

void Solution::setZeroes(vector<vector<int>> &matrix) {
	vector<bool> x_axis(200, false);
	vector<bool> y_axis(200, false);

	if (matrix.empty())
		return;
	int m = matrix.size();
	int n = matrix[0].size();

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (matrix[i][j] == 0) {
				x_axis[i] = true;
				y_axis[j] = true;
			};
		}
	}

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if ((x_axis[i]) || (y_axis[j])) {
				matrix[i][j] = 0;
			}
		}
	}
}
