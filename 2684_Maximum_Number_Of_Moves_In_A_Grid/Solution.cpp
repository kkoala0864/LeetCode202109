#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

int Solution::maxMoves(vector<vector<int>>& grid) {
	int m = grid.size();
	int n = grid[0].size();
	vector<vector<int>> maxStep(m, vector<int>(n, -1));
	int result = 0;

	for (int i = 0 ; i < m ; ++i) maxStep[i][0] = 0;
	for (int i = 0 ; i < n - 1 ; ++i) {
		for (int j = 0 ; j < m ; ++j) {
			if (maxStep[j][i] < 0) continue;
			if (j > 0 && grid[j][i] < grid[j-1][i+1]) {
				maxStep[j-1][i+1] = max(maxStep[j-1][i+1], maxStep[j][i] + 1);
				result = max(result, maxStep[j-1][i+1]);
			}
			if (grid[j][i] < grid[j][i+1]) {
				maxStep[j][i+1] = max(maxStep[j][i+1], maxStep[j][i] + 1);
				result = max(result, maxStep[j][i+1]);
			}
			if (j < m - 1 && grid[j][i] < grid[j+1][i+1]) {
				maxStep[j+1][i+1] = max(maxStep[j+1][i+1], maxStep[j][i] + 1);
				result = max(result, maxStep[j+1][i+1]);
			}
		}
	}
	return result;
}
