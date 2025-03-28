#include <Solution.h>
#include <iostream>

vector<int> dir = {1, 0, -1, 0, 1};

void render(vector<vector<int>> &h, int x, int y, int v, vector<vector<int>> &m) {
	m[x][y] |= (1 << v);

	for (int i = 0; i < 4; ++i) {
		int nx = x + dir[i];
		int ny = y + dir[i + 1];
		if (nx < 0 || ny < 0 || nx >= h.size() || ny >= h[0].size() || h[nx][ny] < h[x][y] || m[nx][ny] & (1 << v))
			continue;
		render(h, nx, ny, v, m);
	}
}

vector<vector<int>> Solution::pacificAtlantic4(vector<vector<int>> &heights) {
	int m = heights.size();
	int n = heights[0].size();

	vector<vector<int>> mark(m, vector<int>(n, 0));

	for (int i = 0; i < n; ++i)
		if (mark[0][i] == 0)
			render(heights, 0, i, 0, mark);
	for (int i = 0; i < m; ++i)
		if (mark[i][0] == 0)
			render(heights, i, 0, 0, mark);

	for (int i = 0; i < n; ++i)
		if (mark[m - 1][i] < 2)
			render(heights, m - 1, i, 1, mark);
	for (int i = 0; i < m; ++i)
		if (mark[i][n - 1] < 2)
			render(heights, i, n - 1, 1, mark);
	vector<vector<int>> result;

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (mark[i][j] == 3) {
				result.emplace_back(vector<int>({i, j}));
			}
		}
	}
	return result;
}
