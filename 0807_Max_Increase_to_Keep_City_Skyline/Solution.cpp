#include <Solution.h>

int Solution::maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
	int n = grid.size();

	vector<int> rowMax(n, 0);
	vector<int> colMax(n, 0);

	for (int i = 0 ; i < n ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			rowMax[i] = max(rowMax[i], grid[i][j]);
			colMax[j] = max(colMax[j], grid[i][j]);
		}
	}
	int result = 0;
	for (int i = 0 ; i < n ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			result += (min(rowMax[i], colMax[j]) - grid[i][j]);
		}
	}
	return result;
}
// n : grid.size();
// TC : O(n*n);
// SC : O(n);
