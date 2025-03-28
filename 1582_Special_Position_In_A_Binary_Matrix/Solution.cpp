#include <Solution.h>
#include <iostream>

int Solution::numSpecial(vector<vector<int>> &mat) {
	int m = mat.size();
	int n = mat[0].size();

	vector<int> row(m, 0);
	vector<int> col(n, 0);

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (mat[i][j] == 1) {
				++row[i];
				++col[j];
			}
		}
	}

	int result = 0;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (mat[i][j] == 1) {
				if (row[i] == 1 && col[j] == 1)
					++result;
			}
		}
	}
	return result;
}
