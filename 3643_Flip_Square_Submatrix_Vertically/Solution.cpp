#include <Solution.h>

vector<vector<int>> Solution::reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
	int m = grid.size();
	int n = grid[0].size();

	for (int i = 0 ; i < (k / 2) ; ++i) {
		for (int j = y ; j < y + k; ++j) {
			swap(grid[x+i][j], grid[x+k-1-i][j]);
		}
	}
	return grid;
}
