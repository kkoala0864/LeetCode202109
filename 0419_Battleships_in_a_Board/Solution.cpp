#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int Solution::countBattleships(vector<vector<char>> &board) {
	int result = 0;

	vector<int> dir = {1, 0, -1, 0, 1};
	for (int i = 0; i < board.size(); ++i) {
		for (int j = 0; j < board[0].size(); ++j) {
			if (board[i][j] == '.')
				continue;
			int cnt = 0;
			for (int di = 0; di < 4; ++di) {
				int nx = i + dir[di];
				int ny = j + dir[di + 1];
				if (nx < 0 || ny < 0 || nx >= board.size() || ny >= board[0].size() || board[nx][ny] == '.')
					continue;
				++cnt;
			}
			if (cnt == 1)
				++result;
			if (cnt == 0)
				result += 2;
		}
	}
	return result >> 1;
}
