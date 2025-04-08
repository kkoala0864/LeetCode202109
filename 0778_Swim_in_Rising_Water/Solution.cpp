#include <Solution.h>
#include <iostream>
#include <queue>
#include <climits>

int Solution::swimInWater(vector<vector<int>>& grid) {
	priority_queue<vector<int>> que, next;
	int m = grid.size();
	int n = grid[0].size();
	vector<vector<int>> minCost(m, vector<int>(n, INT_MAX));

	minCost[0][0] = grid[0][0];
	que.emplace(vector<int>({grid[0][0], 0, 0}));

	vector<int> dir = {1, 0, -1, 0, 1};
	while (!que.empty()) {
		int cost = que.top()[0];
		int x = que.top()[1];
		int y = que.top()[2];
		que.pop();

		if (cost > minCost[x][y]) continue;

		int hCnt = 0;
		for (int i = 0 ; i < 4 ; ++i) {
			int nx = x + dir[i];
			int ny = y + dir[i+1];
			if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
			int nCost = max(cost, grid[nx][ny]);
			if (nCost >= minCost[nx][ny]) continue;
			minCost[nx][ny] = nCost;
			next.emplace(vector<int>({nCost, nx, ny}));
		}
		if (que.empty()) {
			que = move(next);
		}
	}
	return minCost[m-1][n-1];
}
