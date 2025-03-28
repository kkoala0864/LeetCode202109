#include <Solution.h>
#include <iostream>

vector<vector<int>> dir = {{1, 2}, {2, 1}, {-1, 2}, {-2, 1}, {1, -2}, {2, -1}, {-1, -2}, {-2, -1}};

bool dfs(int r, int c, int m, int n, int cnt, vector<vector<int>> &result) {
	if (cnt == m * n)
		return true;

	for (int i = 0; i < dir.size(); ++i) {
		int nx = r + dir[i][0];
		int ny = c + dir[i][1];

		if (nx < 0 || ny < 0 || nx >= m || ny >= n || result[nx][ny] != -1)
			continue;
		result[nx][ny] = cnt;
		if (dfs(nx, ny, m, n, cnt + 1, result))
			return true;
		result[nx][ny] = -1;
	}
	return false;
}

vector<vector<int>> Solution::tourOfKnight(int m, int n, int r, int c) {
	vector<vector<int>> result(m, vector<int>(n, -1));
	result[r][c] = 0;

	dfs(r, c, m, n, 1, result);

	return result;
}
