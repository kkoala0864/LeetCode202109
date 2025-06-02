#include <Solution.h>

int Solution::minMoves(vector<string>& classroom, int energy) {
	int m = classroom.size();
	int n = classroom[0].size();
	queue<vector<int>> que;
	unordered_map<int, int> LitterIdx;

	vector<vector<unordered_map<int, int>>> minCost(m, vector<unordered_map<int, int>>(n, unordered_map<int, int>()));
	for (int i = 0 ; i < m ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			if (classroom[i][j] == 'S') {
				que.emplace(vector<int>({0, 0, energy, i, j}));
				minCost[i][j][0] = energy;
			} else if (classroom[i][j] == 'L') {
				LitterIdx[i * n + j] = LitterIdx.size();
			}
		}
	}
	int fullMask = (1 << LitterIdx.size()) - 1;
	vector<int> dir = {1, 0, -1, 0, 1};

	while (!que.empty()) {
		auto info = que.front();
		que.pop();
		int step = info[0];
		int lmask = info[1];
		int curEnergy = info[2];
		int x = info[3];
		int y = info[4];

		if (lmask == fullMask) {
			return step;
		}
		if (curEnergy == 0) continue;

		for (int i = 0 ; i < 4 ; ++i) {
			int nx = x + dir[i];
			int ny = y + dir[i+1];
			if (nx < 0 || ny < 0 || nx >= m || ny >= n || classroom[nx][ny] == 'X') continue;
			int nMask = classroom[nx][ny] == 'L' ? lmask | (1 << LitterIdx[nx * n + ny]) : lmask;
			int nEnergy = classroom[nx][ny] == 'R' ? energy : curEnergy - 1;
			if (minCost[nx][ny].count(nMask) && minCost[nx][ny][nMask] >= nEnergy) continue;
			minCost[nx][ny][nMask] = nEnergy;
			que.emplace(vector<int>({step + 1, nMask, nEnergy, nx, ny}));
		}
	}
	return -1;
}
