#include <Solution.h>
#include <iostream>

vector<int> Solution::findBall(vector<vector<int>>& grid) {
	int m = grid.size();
	int n = grid[0].size();
	vector<int> cur(n, 0), prev(n, 0);

	for (int i = 0 ; i < n ; ++i) {
		if (grid[m-1][i] == 1) prev[i] = i == n-1 ? -1 : grid[m-1][i] != grid[m-1][i+1] ? -1 : i + 1;
		else prev[i] = i == 0 ? -1 : grid[m-1][i] != grid[m-1][i-1] ? -1 : i - 1;
	}

	for (int i = m - 2 ; i >= 0 ; --i) {
		for (int j = 0 ; j < n ; ++j) {
			if (grid[i][j] == 1) cur[j] = j == n-1 ? -1 : grid[i][j] != grid[i][j+1] ? -1 : prev[j+1];
			else cur[j] = j == 0 ? -1 : grid[i][j] != grid[i][j-1] ? -1 : prev[j-1];
		}
		swap(cur, prev);
	}
	return prev;
}
