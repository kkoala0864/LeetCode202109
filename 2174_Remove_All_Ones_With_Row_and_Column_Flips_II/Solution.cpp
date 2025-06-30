#include <Solution.h>

int Solution::removeOnes(vector<vector<int>>& grid) {
	int n = grid[0].size();
	int m = grid.size();
	int fullMask = 0;
	for (int i = 0 ; i < m ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			if (grid[i][j] == 0) continue;
			int idx = i * n + j;
			fullMask = fullMask | (1 << idx);
		}
	}
	queue<int> que, next;

	que.emplace(fullMask);
	int result = 0;

	while (!que.empty()) {
		int mask = que.front();
		que.pop();

		if (mask == 0) return result;
		for (int i = 0 ; i < 15 ; ++i) {
			if ((mask & (1 << i)) == 0) continue;
			int nextMask = mask;
			int x = i / n;
			int y = i % n;
			for (int j = 0 ; j < m ; ++j) {
				int idx = j * n + y;
				nextMask = nextMask & ~(1 << idx);
			}
			for (int j = 0 ; j < n ; ++j) {
				int idx = x * n + j;
				nextMask = nextMask & ~(1 << idx);
			}
			next.emplace(nextMask);
		}
		if (que.empty()) {
			++result;
			que = move(next);
		}
	}
	return result;
}
