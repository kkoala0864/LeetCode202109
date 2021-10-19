#include <Solution.h>
#include <iostream>

bool Solution::isValidSudoku(vector<vector<char>>& board) {
	int size = board.size();
	vector<vector<bool>> xMap(10, vector<bool>(10, false));
	vector<vector<bool>> yMap(10, vector<bool>(10, false));

	for (int i = 0 ; i < size ; ++i) {
		for (int j = 0 ; j < size ; ++j) {
			if (board[i][j] != '.') {
				if (xMap[i][board[i][j] - '0'] || yMap[j][board[i][j]-'0']) return false;
				xMap[i][board[i][j]-'0'] = true;
				yMap[j][board[i][j]-'0'] = true;
			}
		}
	}

	for (int i = 0 ; i < 3 ; ++i) {
		for (int j = 0 ; j < 3 ; ++j) {
			vector<bool> map(10, false);
			for (int x = 3 * i ; x < (3 * (i + 1)); ++x) {
				for (int y = 3 * j ; y < (3 * (j + 1)) ; ++y) {
					if (board[x][y] != '.') {
						if (map[board[x][y]-'0']) return false;
						map[board[x][y]-'0'] = true;
					}
				}
			}
		}
	}

	return true;
}
