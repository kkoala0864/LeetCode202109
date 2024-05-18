#include <Solution.h>
#include <iostream>

int Solution::numberOfCleanRooms(vector<vector<int>>& room) {
	int result = 1;
	int m = room.size();
	int n = room[0].size();

	vector<int> dir = {0, 1, 0, -1, 0};

	vector<vector<int>> visit(m, vector<int>(n, 0));
	visit[0][0] = 15;

	int di = 0;
	int x = 0, y = 0;
	while (true) {
		int i = 0;
		for (; i < 3 ; ++i) {
			int idx = (di + i) % 4;
			int nx = x + dir[idx];
			int ny = y + dir[idx + 1];
			if (nx < 0 || ny < 0 || nx >= m || ny >= n || room[nx][ny] == 1) continue;
			if (visit[nx][ny] & (1 << di)) return result;
			if (visit[nx][ny] == 0) ++result;
			visit[nx][ny] = visit[nx][ny] | (1 << di);
			x = nx;
			y = ny;
			di = idx;
			break;
		}
		if (i == 3) return result;
	}
	return -1;
}
