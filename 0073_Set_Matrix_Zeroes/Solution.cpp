#include <Solution.h>

void Solution::setZeroes(vector<vector<int>> &matrix) {
	unordered_set<int> rows, cols;
	int m = matrix.size();
	int n = matrix[0].size();

	for (int i = 0 ; i < m ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			if (matrix[i][j] == 0) {
				rows.emplace(i);
				cols.emplace(j);
			}
		}
	}
	for (int i = 0 ; i < m ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			if (rows.count(i) || cols.count(j)) matrix[i][j] = 0;
		}
	}
}
