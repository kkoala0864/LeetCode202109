#include <Solution.h>
#include <iostream>
#include <queue>
#include <climits>

using std::pair;
using std::queue;

vector<vector<int>> Solution::updateMatrix2(vector<vector<int>> &mat) {
	queue<pair<int, int>> que;
	for (int i = 0; i < mat.size(); ++i) {
		for (int j = 0; j < mat[0].size(); ++j) {
			if (mat[i][j] == 0) {
				que.emplace(pair<int, int>(i, j));
			} else {
				mat[i][j] = INT_MAX;
			}
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
			if (nx < 0 || ny < 0 || nx >= mat.size() || ny >= mat[0].size() || mat[nx][ny] == 0)
				continue;
			if (mat[nx][ny] > mat[x][y] + 1) {
				mat[nx][ny] = mat[x][y] + 1;
				que.emplace(pair<int, int>(nx, ny));
			}
		}
	}
	return mat;
}
