#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::pair;
using std::unordered_map;

bool recur(vector<vector<char>> &board, const string &word, int index, const pair<int, int> &loc) {
	if (index == word.size())
		return true;
	int m = board.size();
	int n = board[0].size();

	vector<pair<int, int>> offset = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

	for (const auto &iter : offset) {
		pair<int, int> nextStep(loc.first + iter.first, loc.second + iter.second);
		if (nextStep.first >= 0 && nextStep.first < m && nextStep.second >= 0 && nextStep.second < n) {
			if (board[nextStep.first][nextStep.second] == word[index]) {
				board[nextStep.first][nextStep.second] = '@';
				if (recur(board, word, index + 1, nextStep))
					return true;
				board[nextStep.first][nextStep.second] = word[index];
			}
		}
	}
	return false;
}

bool Solution::exist(vector<vector<char>> &board, string word) {
	int m = board.size();
	int n = board[0].size();
	unordered_map<char, bool> map;

	for (const auto &m : board)
		for (const auto &n : m)
			map[n] = true;

	for (const auto &iter : word)
		if (map.find(iter) == map.end())
			return false;

	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			if (board[i][j] == word[0]) {
				board[i][j] = '@';
				if (recur(board, word, 1, pair<int, int>(i, j)))
					return true;
				board[i][j] = word[0];
			}
	return false;
}
