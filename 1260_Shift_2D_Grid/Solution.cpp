#include <Solution.h>
#include <iostream>

using std::swap;
vector<vector<int>> Solution::shiftGrid(vector<vector<int>> &grid, int k) {
	int m = grid.size(), n = grid[0].size();
	int total = m * n;

	k %= total;
	if (k == 0)
		return grid;

	for (int i = 0; i < k; ++i) {
		int tmp = grid[0][0];
		for (int x = 0; x < m; ++x) {
			for (int y = 0; y < n; ++y) {
				swap(tmp, grid[x][y]);
			}
		}
		swap(tmp, grid[0][0]);
	}
	return grid;
}
