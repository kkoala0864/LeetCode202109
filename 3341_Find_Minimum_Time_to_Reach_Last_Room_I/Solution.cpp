#include <Solution.h>
#include <queue>

int Solution::minTimeToReach(vector<vector<int>>& moveTime) {
	priority_queue<vector<int>, vector<vector<int>>, std::greater<>> pq;

	vector<int> dir = {1, 0, -1, 0, 1};

	pq.emplace(vector<int>({0, 0, 0}));
	vector<vector<int>> minTime(moveTime.size(), vector<int>(moveTime[0].size(), INT_MAX));
	minTime[0][0] = 0;

	while (!pq.empty()) {
		int t = pq.top()[0];
		int x = pq.top()[1];
		int y = pq.top()[2];

		if (t > minTime[x][y]) continue;
		pq.pop();

		for (int i = 0 ; i < 4 ; ++i) {
			int nx = x + dir[i];
			int ny = y + dir[i+1];
			if (nx < 0 || ny < 0 || nx >= moveTime.size() || ny >= moveTime[0].size()) continue;
			int nt = max(t, moveTime[nx][ny]) + 1;
			if (nt >= minTime[nx][ny]) continue;
			minTime[nx][ny] = nt;
			pq.emplace(vector<int>({nt, nx, ny}));
		}
	}
	return minTime.back().back();

}
