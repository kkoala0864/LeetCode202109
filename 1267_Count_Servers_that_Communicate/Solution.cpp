#include <Solution.h>
#include <iostream>

int Solution::countServers(vector<vector<int>>& grid) {
	int m = grid.size();
	int n = grid[0].size();
	vector<int> row(m, 0), col(n, 0);
	for (int i = 0 ; i < m ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			if (grid[i][j] == 0) continue;
			++row[i];
			++col[j];
		}
	}
	int result = 0;
	for (int i = 0 ; i < m ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			if (grid[i][j] == 0) continue;
			if (row[i] > 1 || col[j] > 1) ++result;
		}
	}
	return result;
}
