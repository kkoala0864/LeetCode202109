#include <Solution.h>
#include <iostream>
#include <queue>
#include <algorithm>

using std::priority_queue;
using std::max;

int Solution::trapRainWater(vector<vector<int>>& heightMap) {
	priority_queue<vector<int>, vector<vector<int>>, std::greater<>> pq;
	int m = heightMap.size();
	int n = heightMap[0].size();
	vector<int> dir = {1, 0, -1, 0, 1};
	vector<vector<bool>> visited(m, vector<bool>(n, false));

	for (int i = 0 ; i < m ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			if (i == 0 || j == 0 || i == m-1 || j == n-1) {
				pq.emplace(vector<int>({heightMap[i][j], i, j}));
				visited[i][j] = true;
			}
		}
	}

	int result = 0;
	int curH = -1;
	while (!pq.empty()) {
		int h = pq.top()[0];
		int x = pq.top()[1];
		int y = pq.top()[2];
		pq.pop();

		curH = max(curH, h);
		result += (curH - h);
		for (int i = 0 ; i < 4 ; ++i) {
			int nx = x + dir[i];
			int ny = y + dir[i+1];
			if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
			if (visited[nx][ny]) continue;
			visited[nx][ny] = true;
			pq.emplace(vector<int>({heightMap[nx][ny], nx, ny}));
		}
	}
	return result;
}
