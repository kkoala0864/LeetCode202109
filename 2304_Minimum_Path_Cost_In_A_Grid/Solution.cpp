#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::min;

int Solution::minPathCost(vector<vector<int>> &grid, vector<vector<int>> &moveCost) {
	int m = grid.size(), n = grid[0].size();
	vector<int> cost, next(n, INT_MAX);
	int result = INT_MAX;

	for (int i = 0; i < n; ++i)
		cost.emplace_back(grid[0][i]);

	for (int i = 0; i < m - 1; ++i) {
		for (int j = 0; j < n; ++j) {
			int val = grid[i][j];
			for (int k = 0; k < n; ++k) {
				next[k] = min(cost[j] + moveCost[val][k] + grid[i + 1][k], next[k]);
			}
		}
		cost = move(next);
		next = vector<int>(n, INT_MAX);
	}

	for (int i = 0; i < n; ++i)
		result = min(result, cost[i]);
	return result;
}
