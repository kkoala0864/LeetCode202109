#include <Solution.h>
#include <iostream>
#include <queue>

using std::queue;

int Solution::getFood(vector<vector<char>>& grid) {
	int m = grid.size();
	int n = grid[0].size();

	queue<int> que, next;

	for (int r = 0 ; r < m ; ++r) {
		for (int c = 0 ; c < n ; ++c) {
			if (grid[r][c] == '*') {
				que.emplace(r * n + c);
				grid[r][c] = 'X';
				break;
			}
		}
	}

	vector<int> dir = {1, 0, -1, 0, 1};
	int result = 0;
	while (!que.empty()) {
		int x = que.front() / n;
		int y = que.front() % n;
		que.pop();

		for (int di = 0 ; di < 4 ; ++di) {
			int nx = x + dir[di];
			int ny = y + dir[di+1];
			if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] == 'X') continue;
			if (grid[nx][ny] == '#') return result + 1;
			grid[nx][ny] = 'X';
			next.emplace(nx * n + ny);
		}
		if (que.empty()) {
			++result;
			que = move(next);
		}
	}
	return -1;
}
