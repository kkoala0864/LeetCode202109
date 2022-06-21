#include <Solution.h>
#include <iostream>
#include <queue>
#include <algorithm>

using std::queue;
using std::pair;
using std::min;

void Solution::wallsAndGates(vector<vector<int>>& rooms) {
	queue<pair<int, int>> que, next;

	for (int i = 0 ; i < rooms.size() ; ++i) {
		for (int j = 0 ; j < rooms[0].size() ; ++j) {
			if (rooms[i][j] == 0) que.push({i,j});
		}
	}


	vector<int> dir = {1, 0, -1, 0, 1};
	int step = 1;
	while (!que.empty()) {
		pair<int, int> cur = que.front();
		que.pop();

		for (int i = 0 ; i < 4 ; ++i) {
			int nx = cur.first + dir[i];
			int ny = cur.second + dir[i+1];
			if (nx < 0 || ny < 0 || nx >= rooms.size() || ny >= rooms[0].size()
					|| rooms[nx][ny] == -1 || rooms[nx][ny] == 0) continue;
			if (step < rooms[nx][ny]) {
				rooms[nx][ny] = step;
				next.push({nx, ny});
			}
		}
		if (que.empty()) {
			++step;
			que = move(next);
		}
	}
}
