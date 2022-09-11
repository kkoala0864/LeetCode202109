#include <Solution.h>
#include <iostream>
#include <queue>
#include <climits>

using std::queue;
using std::pair;

int Solution::shortestPathBinaryMatrix3(vector<vector<int>>& grid) {
	if (grid[0][0] == 1) return -1;
	int m = grid.size();
	int n = grid[0].size();

	vector<vector<int>> cnt(m, vector<int>(n, INT_MAX));
	queue<int> que;

	vector<int> axis = {1, 0, -1, 0, 1, -1, -1, 1, 1};
	cnt[0][0] = 1;
	que.emplace(0);
	while (!que.empty()) {
		int x = que.front() / n;
		int y = que.front() % n;
		que.pop();

		for (int i = 0 ; i < 8 ; ++i) {
			int nx = x + axis[i];
			int ny = y + axis[i+1];
			if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] == 1) continue;
			if (cnt[nx][ny] > cnt[x][y] + 1) {
				cnt[nx][ny] = cnt[x][y] + 1;
				que.emplace(nx * n + ny);
			}
		}
	}
	return cnt[m-1][n-1] == INT_MAX ? -1 : cnt[m-1][n-1];
}

