#include <Solution.h>
#include <iostream>

vector<int> dir = {1, 0, -1, 0, 1};

void dfs2(vector<vector<char>>& board, int i, int j) {
	board[i][j] = '#';

	for (int di = 0 ; di < 4 ; ++di) {
		int nx = i + dir[di];
		int ny = j + dir[di+1];
		if (nx < 0 || ny < 0 || nx >= board.size() || ny >= board[0].size() || board[nx][ny] != 'O') continue;
		dfs2(board, nx, ny);
	}
}

void Solution::solve2(vector<vector<char>>& board) {
	int m = board.size();
	int n = board[0].size();

	for (int i = 0 ; i < m ; ++i) {
		if (board[i][0] == 'O') dfs2(board, i, 0);
		if (board[i][n-1] == 'O') dfs2(board, i, n-1);
	}
	for (int j = 0 ; j < n ; ++j) {
		if (board[0][j] == 'O') dfs2(board, 0, j);
		if (board[m-1][j] == 'O') dfs2(board, m-1, j);
	}
	for (int i = 0 ; i < m ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			if (board[i][j] == '#') board[i][j] = 'O';
			else board[i][j] = 'X';
		}
	}
}
