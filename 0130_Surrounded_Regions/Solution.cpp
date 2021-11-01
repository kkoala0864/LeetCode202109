#include <Solution.h>
#include <iostream>

vector<vector<int>> axis = {{1,0}, {0,1}, {-1,0}, {0,-1}};

void dfs(vector<vector<char>>& board, int x, int y) {
	if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size()) return;

	if (board[x][y] == 'T' || board[x][y] == 'X') return;

	board[x][y] = 'T';

	for (const auto& ai : axis) {
		int i = ai[0] + x;
		int j = ai[1] + y;
		dfs(board, i, j);
	}
}

void Solution::solve(vector<vector<char>>& board) {
	int m = board.size();
	int n = board[0].size();

	for (int i = 0 ; i < m ; ++i) {
		if (board[i][0] == 'O') dfs(board, i, 0);
		if (board[i][n-1] == 'O') dfs(board, i, n-1);
	}
	for (int i = 0 ; i < n ; ++i) {
		if (board[0][i] == 'O') dfs(board, 0, i);
		if (board[m-1][i] == 'O') dfs(board, m-1, i);
	}
	for (int i = 0 ; i < m ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			if (board[i][j] == 'T') board[i][j] = 'O';
			else board[i][j] = 'X';
		}
	}
}
