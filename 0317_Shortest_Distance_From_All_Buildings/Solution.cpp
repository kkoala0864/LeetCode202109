#include <Solution.h>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <climits>

// bfs
// enqueue building node
// create vector<vector<unordered_set<>>> to record whether visited or not
// create vector<vector<int>> to record how many build can had visited
// if visited size == building size return curnode distance

int Solution::shortestDistance(vector<vector<int>> &grid) {
	int m = grid.size();
	int n = grid[0].size();

	queue<pair<int, int>> que, next;
	vector<vector<int>> vCnt(m, vector<int>(n, 0));
	vector<vector<int>> dis(m, vector<int>(n, 0));
	vector<pair<int, int>> buildingList;

	for (int i = 0 ; i < grid.size() ; ++i) {
		for (int j = 0 ; j < grid[0].size() ; ++j) {
			if (grid[i][j] == 1) {
				que.emplace(pair<int, int>({i * n + j, i * n + j}));
				buildingList.emplace_back(pair<int, int>(i, j));
			}
		}
	}
	unordered_map<int, int> id;
	for (int i = 0 ; i < buildingList.size() ; ++i) {
		id[buildingList[i].first * n + buildingList[i].second] = i;
	}
	vector<vector<vector<bool>>> visitor(m, vector<vector<bool>>(n, vector<bool>(buildingList.size(), false)));

	int step = 1;
	vector<int> dir = {1, 0, -1, 0, 1};
	int result = INT_MAX;
	while (!que.empty()) {
		int sx = que.front().first / n;
		int sy = que.front().first % n;
		int x = que.front().second / n ;
		int y = que.front().second % n;
		que.pop();

		for (int i = 0 ; i < 4 ; ++i) {
			int nx = x + dir[i];
			int ny = y + dir[i+1];
			if (nx < 0 || ny < 0 || nx >= m || ny >= n ||
			    grid[nx][ny] != 0 || visitor[nx][ny][id[sx*n+sy]]) continue;

			visitor[nx][ny][id[sx * n + sy]] = true;
			++vCnt[nx][ny];
			dis[nx][ny] += step;
			next.emplace(pair<int, int>(sx * n + sy, nx * n + ny));

			if (vCnt[nx][ny] == buildingList.size()) {
				result = min(result, dis[nx][ny]);
			}
		}
		if (que.empty()) {
			++step;
			que = move(next);
		}
	}
	return result == INT_MAX ? -1 : result;
}
