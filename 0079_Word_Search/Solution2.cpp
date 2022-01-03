#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;
using std::cout;
using std::endl;

vector<vector<int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};

bool recur(vector<vector<char>>& board, string& word, int idx, int i, int j) {
	if (idx == word.size()-1) return true;

	board[i][j] = '@';
	for (const auto& iter : dir) {
		int x = i + iter[0];
		int y = j + iter[1];
		if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && board[x][y] != '@' && board[x][y] == word[idx+1]) {
			if (recur(board, word, idx+1, x, y)) return true;
		}
	}
	board[i][j] = word[idx];
	return false;
}

bool Solution::exist2(vector<vector<char>>& board, string word) {
	unordered_map<char, vector<vector<int>>> map;
	for (int i = 0 ; i < board.size() ; ++i) {
		for (int j = 0 ; j < board[0].size() ; ++j) {
			map[board[i][j]].push_back({i,j});
		}
	}

	for (const auto& iter : word) if (map.find(iter) == map.end()) return false;

	for (const auto& loc : map[word[0]]) {
		if (recur(board, word, 0, loc[0], loc[1])) return true;
	}
	return false;
}
