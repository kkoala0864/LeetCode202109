#include <Solution.h>
#include <iostream>

// board[x][y] = 2 -> 1 -> 0
// board[x][y] = 3 -> 0 -> 1
void Solution::gameOfLife(vector<vector<int>> &board) {
	int m = board.size(), n = board[0].size();
	vector<vector<int>> axis = {{1, 0}, {0, 1}, {1, 1}, {-1, 0}, {0, -1}, {-1, -1}, {1, -1}, {-1, 1}};

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			int cnt = 0;
			for (const auto &ai : axis) {
				int x = i + ai[0];
				int y = j + ai[1];
				if (x < 0 || x >= m || y < 0 || y >= n)
					continue;
				if (board[x][y] == 1 || board[x][y] == 2)
					++cnt;
			}
			if (board[i][j] && (cnt < 2 || cnt > 3))
				board[i][j] = 2;
			else if (!board[i][j] && cnt == 3)
				board[i][j] = 3;
		}
	}
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (board[i][j] == 2)
				board[i][j] = 0;
			else if (board[i][j] == 3)
				board[i][j] = 1;
		}
	}
}
