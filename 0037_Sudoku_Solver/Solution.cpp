#include <Solution.h>
#include <iostream>

using std::pair;

bool dfs(vector<pair<int, int>> &e, vector<vector<char>> &board, int idx,
         vector<vector<bool>> &x, vector<vector<bool>> &y, vector<vector<bool>> &b) {
	if (idx == e.size())
		return true;

	auto cur = e[idx];
	int bIdx = (cur.first / 3) * 3 + (cur.second / 3);
	for (int i = 0; i < 9; ++i) {
		if (x[cur.first][i] || y[cur.second][i] || b[bIdx][i])
			continue;
		x[cur.first][i] = true;
		y[cur.second][i] = true;
		b[bIdx][i] = true;
		board[cur.first][cur.second] = '1' + i;
		if (dfs(e, board, idx + 1, x, y, b))
			return true;
		x[cur.first][i] = false;
		y[cur.second][i] = false;
		b[bIdx][i] = false;
	}
	return false;
}

void Solution::solveSudoku(vector<vector<char>> &board) {
	vector<vector<bool>> xMap(9, vector<bool>(9, false));
	vector<vector<bool>> yMap(9, vector<bool>(9, false));
	vector<vector<bool>> bMap(9, vector<bool>(9, false));
	vector<pair<int, int>> e;

	int xSize = board.size();
	int ySize = board[0].size();
	for (int i = 0; i < xSize; ++i) {
		for (int j = 0; j < ySize; ++j) {
			if (board[i][j] == '.') {
				e.push_back({i, j});
				continue;
			}
			xMap[i][board[i][j] - '1'] = true;
			yMap[j][board[i][j] - '1'] = true;
			bMap[(i / 3 * 3) + j / 3][board[i][j] - '1'] = true;
		}
	}

	dfs(e, board, 0, xMap, yMap, bMap);
}
