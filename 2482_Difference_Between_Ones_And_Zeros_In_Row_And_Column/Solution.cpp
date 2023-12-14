#include <Solution.h>
#include <iostream>

vector<vector<int>> Solution::onesMinusZeros(vector<vector<int>>& grid) {
	int m = grid.size();
	int n = grid[0].size();

	vector<int> r(m, 0);
	vector<int> c(n, 0);

	for (int i = 0 ; i < m ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			if (grid[i][j] == 1) {
				++r[i];
				++c[j];
			}
		}
	}

	for (int i = 0 ; i < m ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			grid[i][j] = 2 * r[i] + 2 * c[j] - (m + n);
		}
	}
	return grid;

}
