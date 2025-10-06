#include <Solution.h>

int find(vector<int>& root, int idx) {
	if (root[idx] == idx) return idx;
	return root[idx] = find(root, root[idx]);
}

int Solution::swimInWater(vector<vector<int>>& grid) {
	priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
	int m = grid.size();
	int n = grid[0].size();

	for (int i = 0 ; i < m ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			pq.emplace(vector<int>({grid[i][j], i, j}));
		}
	}

	vector<int> root;
	for (int i = 0 ; i < (m * n) ; ++i) root.emplace_back(i);

	vector<int> dir = {1, 0, -1, 0, 1};
	while (!pq.empty()) {
		int curDepth = pq.top()[0];
		int x = pq.top()[1];
		int y = pq.top()[2];
		pq.pop();

		for (int i = 0 ; i < 4 ; ++i) {
			int nx = x + dir[i];
			int ny = y + dir[i+1];
			if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] > curDepth) continue;
			int lr = find(root, x * n + y);
			int rr = find(root, nx * n + ny);
			if (lr == rr) continue;
			root[lr] = root[rr] = min(lr, rr);
		}
		if (find(root, 0) == find(root, m * n - 1)) return curDepth;
	}
	return -1;
}
