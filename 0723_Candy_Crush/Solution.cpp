#include <Solution.h>
#include <iostream>

bool crush(vector<vector<int>> &board) {
	vector<vector<int>> mask = board;
	int m = board.size();
	int n = board[0].size();
	bool ret = false;

	for (int i = 0; i < m; ++i) {
		int iter = -1;
		for (int j = 0; j < n; ++j) {
			if (iter == -1) {
				iter = j;
			} else if (board[i][j] == board[i][iter] && board[i][j] != 0) {
				continue;
			} else {
				if (j - iter > 2) {
					ret = true;
					while (iter < j) {
						mask[i][iter++] = -1;
					}
				} else {
					iter = j;
				}
			}
		}
		if (n - iter > 2) {
			ret = true;
			while (iter < n) {
				mask[i][iter++] = -1;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		int iter = -1;
		for (int j = 0; j < m; ++j) {
			if (iter == -1) {
				iter = j;
			} else if (board[j][i] == board[iter][i] && board[j][i] != 0) {
				continue;
			} else {
				if (j - iter > 2) {
					ret = true;
					while (iter < j) {
						mask[iter++][i] = -1;
					}
				} else {
					iter = j;
				}
			}
		}
		if (m - iter > 2) {
			ret = true;
			while (iter < m) {
				mask[iter++][i] = -1;
			}
		}
	}
	board = move(mask);
	return ret;
}

void drop(vector<vector<int>> &board) {
	int m = board.size();
	int n = board[0].size();
	for (int i = 0; i < n; ++i) {
		int iter = m - 1;
		for (int j = m - 1; j >= 0; --j) {
			if (board[j][i] > 0) {
				board[iter--][i] = board[j][i];
			}
		}
		while (iter >= 0) {
			board[iter--][i] = 0;
		}
	}
}

vector<vector<int>> Solution::candyCrush(vector<vector<int>> &board) {
	while (crush(board)) {
		drop(board);
	}
	return board;
}
