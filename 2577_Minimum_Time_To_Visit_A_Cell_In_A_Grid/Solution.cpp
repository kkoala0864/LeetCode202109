#include <Solution.h>
#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>

using std::max;
using std::priority_queue;
using std::min;
using std::cout;
using std::endl;

int Solution::minimumTime(vector<vector<int>>& grid) {
	if (grid[0][0] > 0) return -1;
	int m = grid.size();
	int n = grid[0].size();
	vector<vector<int>> mc(m, vector<int>(n, INT_MAX));
	priority_queue<vector<int>, vector<vector<int>>, std::greater<vector<int>>> pq;

	mc[0][0] = 0;
	pq.emplace(vector<int>({0, 0, 0}));

	vector<int> dir = {1, 0, -1, 0, 1};

	while (!pq.empty()) {
		int curT = pq.top()[0];
		int x = pq.top()[1];
		int y = pq.top()[2];
		int check = pq.top()[3];
		pq.pop();

		if (curT > mc[x][y]) continue;
		if (x == m-1 && y == n-1) return mc[m-1][n-1];
		int lessCnt = 0;
		int nextT = curT + 1;
		for (int i = 0 ; i < 4 ; ++i) {
			int nx = x + dir[i];
			int ny = y + dir[i+1];
			if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
			if (nextT >= grid[nx][ny]) {
				++lessCnt;
				continue;
			}
		}
		for (int i = 0 ; i < 4 ; ++i) {
			int nx = x + dir[i];
			int ny = y + dir[i+1];
			if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
			if (nextT >= mc[nx][ny]) continue;
			if (nextT < grid[nx][ny]) {
				if (lessCnt > 0) {
					mc[nx][ny] = (grid[nx][ny] - curT) & 1 ? grid[nx][ny] : grid[nx][ny] + 1;
					pq.emplace(vector<int>({mc[nx][ny], nx, ny}));
				}
			} else {
				mc[nx][ny] = nextT;
				pq.emplace(vector<int>({mc[nx][ny], nx, ny}));
			}
		}
	}
	return -1;
}
