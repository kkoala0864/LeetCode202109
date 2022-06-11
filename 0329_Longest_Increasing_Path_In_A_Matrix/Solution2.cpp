#include <Solution.h>
#include <iostream>
#include <queue>

using std::pair;
using std::queue;

int Solution::longestIncreasingPath2(vector<vector<int>>& matrix) {
	queue<pair<int, int>> que, next;
	int m = matrix.size(), n = matrix[0].size();
	vector<int> dir = {1, 0, -1, 0, 1};
	vector<vector<int>> weight(m, vector<int>(n, 0));
	for (int i = 0 ; i < m ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			int cnt = 0;
			for (int k = 0 ; k < 4 ; ++k) {
				int nx = i + dir[k];
				int ny = j + dir[k+1];
				if (nx < 0 || ny < 0 || nx >= m || ny >= n || matrix[nx][ny] >= matrix[i][j]) continue;
				++cnt;
			}
			if (cnt == 0) que.push({i, j});
			weight[i][j] = cnt;
		}
	}

	int result = 0;
	while (!que.empty()) {
		auto cur = que.front();
		que.pop();

		for (int k = 0 ; k < 4 ; ++k) {
			int nx = cur.first + dir[k];
			int ny = cur.second + dir[k+1];
			if (nx < 0 || ny < 0 || nx >= m || ny >= n || matrix[nx][ny] <= matrix[cur.first][cur.second]) continue;
			--weight[nx][ny];
			if (weight[nx][ny] == 0) next.push({nx, ny});
		}

		if (que.empty()) {
			++result;
			que = move(next);
		}
	}
	return result;
}
