#include <Solution.h>

void dfs(int x, int y, const vector<int>& dir, const string& ds,
		const string& rds, vector<vector<int>>& cost, vector<int>& target, GridMaster& master) {

	if (master.isTarget()) {
		target[0] = x;
		target[1] = y;
		return;
	}

	for (int i = 0 ; i < 4 ; ++i) {
		if (!master.canMove(ds[i])) continue;
		int nx = x + dir[i];
		int ny = y + dir[i+1];
		if (cost[nx][ny] != INT_MAX) continue;
		cost[nx][ny] = master.move(ds[i]);
		if (cost[nx][ny] == -1) continue;
		dfs(nx, ny, dir, ds, rds, cost, target, master);
		master.move(rds[i]);
	}
}

int Solution::findShortestPath(GridMaster &master) {
	int size = 201;
	int offset = 100;
	vector<int> dir = {1, 0, -1, 0, 1};
	string ds = "DLUR";
	string rds = "URDL";

	vector<vector<int>> cost(size, vector<int>(size, INT_MAX));
	vector<int> target(2, INT_MAX);

	dfs(offset, offset, dir, ds, rds, cost, target, master);

	if (target[0] == INT_MAX) return -1;
	priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
	pq.emplace(vector<int>({0, offset, offset}));
	vector<vector<int>> minCost(size, vector<int>(size, INT_MAX));
	minCost[offset][offset] = 0;

	while (!pq.empty()) {
		int c = pq.top()[0];
		int x = pq.top()[1];
		int y = pq.top()[2];
		pq.pop();

		if (c > minCost[x][y]) continue;
		if (x == target[0] && y == target[1]) return c;
		for (int i = 0 ; i < 4 ; ++i) {
			int nx = x + dir[i];
			int ny = y + dir[i+1];
			if (cost[nx][ny] == -1 || cost[nx][ny] == INT_MAX) continue;
			if ((cost[nx][ny] + c) >= minCost[nx][ny]) continue;
			minCost[nx][ny] = cost[nx][ny] + c;
			pq.emplace(vector<int>({minCost[nx][ny], nx, ny}));
		}
	}
	return -1;
}
