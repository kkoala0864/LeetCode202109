#include <Solution.h>
#include <iostream>
#include <queue>
#include <climits>

using std::pair;
using std::queue;

vector<vector<int>> Solution::updateMatrix(vector<vector<int>> &mat) {
	queue<pair<int, int>> que;
	vector<vector<int>> result(mat.size(), vector<int>(mat[0].size(), INT_MAX));

	for (int i = 0; i < mat.size(); ++i) {
		for (int j = 0; j < mat[0].size(); ++j) {
			if (mat[i][j] == 0) {
				que.emplace(pair<int, int>(i, j));
				result[i][j] = 0;
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
			if (result[nx][ny] > result[x][y] + 1) {
				result[nx][ny] = result[x][y] + 1;
				que.push({nx, ny});
			}
		}
	}
	return result;
}
