#include <Solution.h>
#include <iostream>
#include <climits>
#include <queue>

using std::priority_queue;
using std::pair;
using std::cout;
using std::endl;

int Solution::minimumObstacles2(vector<vector<int>>& grid) {
	int n = grid[0].size();
	int m = grid.size();
	vector<int> cost (m * n, INT_MAX);

	vector<int> axis = {1, 0, -1, 0, 1};

	cost[0] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> pq;

	pq.emplace(pair<int, int>(0, 0));
	while (!pq.empty()) {
		int curX = pq.top().second / n;
		int curY = pq.top().second % n;
		int curC = pq.top().first;
		int curIdx = pq.top().second;
		pq.pop();

		for (int i = 0 ; i < 4 ; ++i) {
			int nx = curX + axis[i];
			int ny = curY + axis[i+1];
			if (nx < 0 || ny < 0 || nx >= m || ny >= n || curC > cost[curIdx]) continue;
			int idx = nx * n + ny;
			if (cost[idx] > (cost[curIdx] + grid[nx][ny])) {
				cost[idx] = cost[curIdx] + grid[nx][ny];
				pq.emplace(pair<int, int>(cost[idx], idx));
			}
		}
	}
	return cost[m * n -1];
}
