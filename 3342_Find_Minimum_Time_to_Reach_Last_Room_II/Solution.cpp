#include <Solution.h>

int Solution::minTimeToReach(vector<vector<int>>& moveTime) {
	priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;

	int m = moveTime.size(), n = moveTime[0].size();

	vector<vector<int>> minTime(m, vector<int>(n, INT_MAX));

	minTime[0][0] = 0;
	pq.emplace(vector<int>({0, 0, 0}));

	vector<int> dir = {1, 0, -1, 0, 1};

	while (!pq.empty()) {
		int t = pq.top()[0];
		int x = pq.top()[1];
		int y = pq.top()[2];
		pq.pop();

		if (x == m - 1 && y == n - 1) return t;
		if (t > minTime[x][y]) continue;

		for (int i = 0 ; i < 4 ; ++i) {
			int nx = x + dir[i];
			int ny = y + dir[i+1];
			if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
			int nt = max(t, moveTime[nx][ny]) + (((nx + ny) & 1) == 1 ? 1 : 2);
			if (minTime[nx][ny] <= nt) continue;
			minTime[nx][ny] = nt;
			pq.emplace(vector<int>({nt, nx, ny}));
		}
	}
	return minTime.back().back();
}
