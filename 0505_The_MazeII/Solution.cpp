#include <Solution.h>
#include <iostream>
#include <queue>
#include <climits>

using std::pair;
using std::queue;

int Solution::shortestDistance(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
	int m = maze.size();
	int n = maze[0].size();

	vector<vector<int>> minStep(m, vector<int>(n, INT_MAX));
	queue<pair<int, int>> que;
	que.emplace(pair<int, int>(start[0] * n + start[1], 0));
	minStep[start[0]][start[1]] = 0;
	vector<int> axis = {1, 0, -1, 0, 1};

	while (!que.empty()) {
		auto cur = que.front();
		que.pop();

		int x = cur.first / n;
		int y = cur.first % n;

		if (cur.second > minStep[x][y])
			continue;

		for (int i = 0; i < 4; ++i) {
			int step = 0;
			int nx = x;
			int ny = y;
			while (nx >= 0 && ny >= 0 && nx < m && ny < n && maze[nx][ny] == 0) {
				++step;
				nx += axis[i];
				ny += axis[i + 1];
			}

			nx -= axis[i];
			ny -= axis[i + 1];
			--step;

			if (minStep[nx][ny] > (cur.second + step)) {
				minStep[nx][ny] = cur.second + step;
				que.emplace(pair<int, int>(nx * n + ny, cur.second + step));
			}
		}
	}
	return minStep[destination[0]][destination[1]] == INT_MAX ? -1 : minStep[destination[0]][destination[1]];
}
