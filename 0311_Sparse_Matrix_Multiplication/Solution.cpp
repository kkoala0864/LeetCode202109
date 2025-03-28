#include <Solution.h>
#include <iostream>

using std::pair;

vector<vector<int>> Solution::multiply(vector<vector<int>> &mat1, vector<vector<int>> &mat2) {
	vector<vector<int>> result(mat1.size(), vector<int>(mat2[0].size(), 0));

	for (int i = 0; i < mat1.size(); ++i) {
		for (int k = 0; k < mat1[0].size(); ++k) {
			if (mat1[i][k] == 0)
				continue;
			int arg1 = mat1[i][k];
			for (int j = 0; j < mat2[0].size(); ++j) {
				result[i][j] += (arg1 * mat2[k][j]);
			}
		}
	}
	return result;
}

vector<vector<pair<int, int>>> compressMatrix(vector<vector<int>> &matrix) {
	int r = matrix.size();
	int c = matrix[0].size();

	vector<vector<pair<int, int>>> result(r);

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (matrix[i][j] != 0) {
				result[i].emplace_back(matrix[i][j], j);
			}
		}
	}
	return result;
}

vector<vector<int>> Solution::multiply2(vector<vector<int>> &mat1, vector<vector<int>> &mat2) {
	int m = mat1.size();
	int k = mat1[0].size();
	int n = mat2[0].size();

	vector<vector<pair<int, int>>> A = compressMatrix(mat1);
	vector<vector<pair<int, int>>> B = compressMatrix(mat2);
	vector<vector<int>> result(m, vector<int>(n, 0));

	for (int mat1r = 0; mat1r < m; ++mat1r) {
		for (auto aiter : A[mat1r]) {
			for (auto biter : B[aiter.second]) {
				result[mat1r][biter.second] += (aiter.first * biter.first);
			}
		}
	}
	return result;
}
