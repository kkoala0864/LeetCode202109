#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::reverse;
using std::cout;
using std::endl;

bool check(const string& golden, const string& str) {
	for (int i = 0 ; i < golden.size() ; ++i) {
		if (str[i] == ' ' || golden[i] == str[i]) continue;
		return false;
	}
	return true;
}

bool Solution::placeWordInCrossword(vector<vector<char>>& board, string word) {
	int m = board.size();
	int n = board[0].size();

	vector<string> candidate;
	for (int i = 0 ; i < m ; ++i) {
		string tmp;
		for (int j = 0 ; j < n ; ++j) {
			if (board[i][j] == '#') {
				if (tmp.size() == word.size()) {
					candidate.emplace_back(tmp);
				}
				tmp.clear();
			} else {
				tmp.push_back(board[i][j]);
			}
		}
		if (tmp.size() == word.size()) {
			candidate.emplace_back(tmp);
		}
	}
	for (int i = 0 ; i < n ; ++i) {
		string tmp;
		for (int j = 0 ; j < m ; ++j) {
			if (board[j][i] == '#') {
				if (tmp.size()== word.size()) {
					cout << tmp << endl;
					candidate.emplace_back(tmp);
				}
				tmp.clear();
			} else {
				tmp.push_back(board[j][i]);
			}
		}
		if (tmp.size() == word.size()) {
			candidate.emplace_back(tmp);
		}
	}
	string rev = word;
	reverse(rev.begin(), rev.end());
	for (const auto& c : candidate) {
		if (check(word, c)) return true;
		if (check(rev, c)) return true;
	}
	return false;
}
