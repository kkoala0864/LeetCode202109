#include <Solution.h>
#include <iostream>

void dfs(vector<vector<int>> &heights, vector<vector<int>> &record, int x, int y, int mark) {
	if (record[x][y] == mark || record[x][y] == 3)
		return;
	record[x][y] += mark;

	vector<int> axis = {1, 0, -1, 0, 1};
	for (int i = 0; i < 4; ++i) {
		int nx = x + axis[i];
		int ny = y + axis[i + 1];

		if (nx < 0 || ny < 0 || nx >= heights.size() || ny >= heights[0].size()
		    || heights[nx][ny] < heights[x][y] || record[nx][ny] == mark || record[nx][ny] == 3)
			continue;

		dfs(heights, record, nx, ny, mark);
	}
}

vector<vector<int>> Solution::pacificAtlantic3(vector<vector<int>> &heights) {
	int m = heights.size();
	int n = heights[0].size();
	vector<vector<int>> record(m, vector<int>(n, 0));
	vector<vector<int>> result;

	for (int i = 0; i < m; ++i) {
		dfs(heights, record, i, 0, 1);
		dfs(heights, record, i, n - 1, 2);
	}

	for (int i = 0; i < n; ++i) {
		dfs(heights, record, 0, i, 1);
		dfs(heights, record, m - 1, i, 2);
	}

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (record[i][j] == 3)
				result.push_back({i, j});
		}
	}
	return result;
}
