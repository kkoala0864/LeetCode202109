#include <Solution.h>
#include <iostream>

vector<int> dir = {1, 0, -1, 0, 1, -1, -1, 1, 1};
void dfs(vector<vector<char>>& b, vector<vector<int>>& cnt, int x, int y) {
	if (b[x][y] != 'E') return;

	if (cnt[x][y] > 0) {
		b[x][y] = cnt[x][y] + '0';
		return;
	} else {
		b[x][y] = 'B';
	}

	for (int i = 0 ; i < 8 ; ++i) {
		int nx = x + dir[i];
		int ny = y + dir[i+1];
		if (nx < 0 || ny < 0 || nx >= b.size() || ny >= b[0].size() || b[nx][ny] != 'E') continue;
		dfs(b, cnt, nx, ny);
	}
}

vector<vector<char>> Solution::updateBoard(vector<vector<char>>& board, vector<int>& click) {
	if (board[click[0]][click[1]] == 'M') {
		board[click[0]][click[1]] = 'X';
		return board;
	}

	int m = board.size();
	int n = board[0].size();
	vector<vector<int>> cnt(m, vector<int>(n, 0));

	for (int i = 0 ; i < m ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			if (board[i][j] != 'M') continue;
			for (int di = 0 ; di < 8 ; ++di) {
				int nx = i + dir[di];
				int ny = j + dir[di+1];
				if (nx < 0 || ny < 0 || nx >= m || ny >= n || board[nx][ny] != 'E') continue;
				++cnt[nx][ny];
			}
		}
	}

	dfs(board, cnt, click[0], click[1]);
	return board;
}
