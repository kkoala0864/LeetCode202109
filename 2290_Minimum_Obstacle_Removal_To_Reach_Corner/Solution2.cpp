#include <Solution.h>
#include <iostream>
#include <queue>
#include <climits>

using std::priority_queue;
using std::pair;

int Solution::minimumObstacles2(vector<vector<int>>& grid) {
	int m = grid.size();
	int n = grid[0].size();

	vector<vector<int>> minObs(m, vector<int>(n, INT_MAX));
	minObs[0][0] = grid[0][0];

	priority_queue<vector<int>, vector<vector<int>>, std::greater<vector<int>>> pq;

	vector<int> dir = {1, 0, -1, 0, 1};

	pq.emplace(vector<int>({minObs[0][0], 0, 0}));

	while (!pq.empty()) {
		int oc = pq.top()[0];
		int x = pq.top()[1];
		int y = pq.top()[2];
		pq.pop();

		if (x == m-1 && y == n-1) return oc;
		if (minObs[x][y] > oc) continue;

		for (int i = 0 ; i < 4 ; ++i) {
			int nx = x + dir[i];
			int ny = y + dir[i+1];
			if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
			if (minObs[nx][ny] <= oc + grid[nx][ny]) continue;
			minObs[nx][ny] = oc + grid[nx][ny];
			pq.emplace(vector<int>({minObs[nx][ny], nx, ny}));
		}
	}
	return -1;
}
