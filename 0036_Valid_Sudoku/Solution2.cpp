#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;
bool Solution::isValidSudoku2(vector<vector<char>>& board) {
	for (int i = 0 ; i < board.size() ; ++i) {
		vector<bool> row(9, false);
		vector<bool> col(9, false);
		for (int j = 0 ; j < board.size() ; ++j) {
			if (board[i][j] != '.') {
				if (row[board[i][j]-'0']) return false;
				row[board[i][j]-'0'] = true;
			}
			if (board[j][i] != '.') {
				if (col[board[j][i] - '0']) return false;
				col[board[j][i]-'0'] = true;
			}
		}
	}

	for (int i = 0 ; i < 3 ; ++i) {
		for (int j = 0 ; j < 3 ; ++j) {
			vector<bool> check(9, false);
			for (int k = i * 3 ; k < ((i + 1) * 3) ; ++k) {
				for (int l = j * 3 ; l < ((j + 1) * 3) ; ++l) {
					if (board[k][l] != '.') {
						if (check[board[k][l]-'0']) return false;
						check[board[k][l]-'0'] = true;
					}
				}
			}
		}
	}
	return true;
}
