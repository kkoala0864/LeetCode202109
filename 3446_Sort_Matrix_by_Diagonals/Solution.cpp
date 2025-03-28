#include <Solution.h>
#include <iostream>
#include <queue>

using std::priority_queue;
// -2 -1 0 1 2 => 2 * 3 - 1

vector<vector<int>> Solution::sortMatrix(vector<vector<int>> &grid) {
	int n = grid.size();
	vector<priority_queue<int>> decrease(n);
	vector<priority_queue<int, vector<int>, std::greater<>>> increase(n - 1);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int idx = i - j;
			if (idx >= 0) {
				decrease[idx].emplace(grid[i][j]);
			} else {
				increase[idx + n - 1].emplace(grid[i][j]);
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int idx = i - j;
			if (idx >= 0) {
				grid[i][j] = decrease[idx].top();
				decrease[idx].pop();
			} else {
				grid[i][j] = increase[idx + n - 1].top();
				increase[idx + n - 1].pop();
			}
		}
	}
	return grid;
}
