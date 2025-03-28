#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::max;
using std::min;
using std::pair;

vector<pair<int, int>> axis = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};

bool dfs(const vector<vector<int>> &grid, int mid, vector<vector<int>> &flag, int x, int y) {
	if (x == grid.size() - 1 && y == grid[0].size() - 1)
		return true;

	for (const auto &ai : axis) {
		int i = x + ai.first;
		int j = y + ai.second;

		if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] < mid || flag[i][j])
			continue;
		flag[i][j] = true;
		if (dfs(grid, mid, flag, i, j))
			return true;
	}
	return false;
}

int Solution::maximumMinimumPath(vector<vector<int>> &grid) {
	vector<vector<int>> flag(grid.size(), vector<int>(grid[0].size(), false));
	int left = 0, right = min(grid[0][0], grid.back().back());

	int mid = 0;
	while (left <= right) {
		for (auto &iter : flag)
			fill(iter.begin(), iter.end(), false);
		mid = (left + right) / 2;

		if (dfs(grid, mid, flag, 0, 0))
			left = mid + 1;
		else
			right = mid - 1;
	}
	return right;
}
