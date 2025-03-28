#include <Solution.h>
#include <iostream>
#include <queue>
#include <climits>

using std::pair;
using std::queue;

vector<vector<int>> Solution::updateMatrix3(vector<vector<int>> &mat) {
	int m = mat.size();
	int n = mat[0].size();

	queue<pair<int, int>> que;

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (mat[i][j] == 0)
				que.emplace(pair<int, int>(i, j));
			else
				mat[i][j] = INT_MAX;
		}
	}

	vector<int> axis = {1, 0, -1, 0, 1};
	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = x + axis[i];
			int ny = y + axis[i + 1];
			if (nx < 0 || ny < 0 || nx >= m || ny >= n)
				continue;
			if (mat[nx][ny] > mat[x][y] + 1) {
				mat[nx][ny] = mat[x][y] + 1;
				que.emplace(pair<int, int>(nx, ny));
			}
		}
	}
	return mat;
}
