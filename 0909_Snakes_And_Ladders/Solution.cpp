#include <Solution.h>

pair<int, int> getCordinate(int v, int n) {
	v -= 1;
	int x = v / n;
	int y = v % n;
	if (x & 1) {
		y = n - 1 - y;
	}
	return pair<int, int>(n - 1 - x, y);
}

int Solution::snakesAndLadders(vector<vector<int>> &board) {
	int n = board.size();

	queue<pair<int, int>> que;
	que.emplace(pair<int, int>(0, 1));
	vector<int> minStep(n * n + 1, INT_MAX);
	minStep[1] = 0;

	while (!que.empty()) {
		int curStep = que.front().first;
		int curIdx = que.front().second;
		que.pop();

		if (curIdx == (n * n)) break;
		if (curStep > minStep[curIdx]) continue;

		for (int i = 1 ; i <= 6 ; ++i) {
			if ((curIdx + i) > (n * n)) break;
			int next = curIdx + i;
			auto [nx, ny] = getCordinate(next, n);
			if (board[nx][ny] != -1) {
				next = board[nx][ny];
			}
			if ((curStep + 1) >= minStep[next]) continue;
			minStep[next] = curStep + 1;
			que.emplace(pair<int, int>(curStep + 1, next));
		}
	}
	return minStep.back() == INT_MAX ? -1 : minStep.back();
}
