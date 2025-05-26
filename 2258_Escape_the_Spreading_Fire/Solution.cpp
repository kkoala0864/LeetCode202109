#include <Solution.h>

int Solution::maximumMinutes(vector<vector<int>>& grid) {
	int m = grid.size();
	int n = grid[0].size();
	vector<vector<int>> minFire(m, vector<int>(n, INT_MAX));
	priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;

	for (int i = 0 ; i < m ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			if (grid[i][j] == 1) {
				pq.emplace(vector<int>({0, i, j}));
				minFire[i][j] = 0;
			}
		}
	}

	vector<int> dir = {1, 0, -1, 0, 1};
	while (!pq.empty()) {
		int ct = pq.top()[0];
		int x = pq.top()[1];
		int y = pq.top()[2];
		pq.pop();

		if (ct > minFire[x][y]) continue;

		for (int i = 0 ; i < 4 ; ++i) {
			int nx = x + dir[i];
			int ny = y + dir[i+1];
			if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] == 2 || (ct + 1) >= minFire[nx][ny]) continue;
			minFire[nx][ny] = ct + 1;
			pq.emplace(vector<int>({ct + 1, nx, ny}));
		}
	}

	if (minFire[0][0] == 0) return -1;
	pq.emplace(vector<int>({0, 0, 0, minFire[0][0] - 0}));
	vector<vector<int>> cTime(m, vector<int>(n, INT_MAX));
	cTime[0][0] = 0;

	int result = -1;
	while (!pq.empty()) {
		int ct = pq.top()[0];
		int x = pq.top()[1];
		int y = pq.top()[2];
		int minDelay = pq.top()[3];
		pq.pop();

		if (ct > cTime[x][y]) continue;
		if (x == m-1 && y == n-1 && ct <= minFire[x][y]) {
			result = max(result, min({minDelay, minFire[x][y] - ct, (int)1e9}));
			continue;
		}

		minDelay = min(minDelay, minFire[x][y] - 1 - ct);

		for (int i = 0 ; i < 4 ; ++i) {
			int nx = x + dir[i];
			int ny = y + dir[i+1];
			if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] == 2 ||
					(ct + 1) > minFire[nx][ny] || (((nx != m-1) || (ny != n-1)) && (ct + 1) >= cTime[nx][ny])) continue;
			pq.emplace(vector<int>({ct + 1, nx, ny, minDelay}));
			cTime[nx][ny] = ct + 1;
		}
	}
	return result;
}
