#include <Solution.h>
#include <iostream>

using std::swap;

vector<vector<int>> Solution::transpose(vector<vector<int>>& matrix) {
	int m = matrix.size(), n = matrix[0].size();
	if (m == n) {
		for (int i = 0 ; i < m ; ++i) {
			for (int j = i ; j < n ; ++j) {
				if (i != j) {
					swap(matrix[i][j], matrix[j][i]);
				}
			}
		}
		return matrix;
	} else {
		vector<vector<int>> result(n, vector<int>(m, 0));
		for (int i = 0 ; i < m ; ++i) {
			for (int j = 0 ; j < n ; ++j) {
				result[j][i] = matrix[i][j];
			}
		}
		return result;
	}
}
