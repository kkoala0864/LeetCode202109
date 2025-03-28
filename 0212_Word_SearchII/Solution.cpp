#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::pair;
using std::unordered_map;

vector<vector<int>> axis = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void BuildTrie(Trie *node, const string &word, int wordIdx) {
	if (wordIdx == word.size()) {
		node->word = word;
		return;
	}
	if (node->next[word[wordIdx] - 'a'] == nullptr)
		node->next[word[wordIdx] - 'a'] = new Trie();
	node = node->next[word[wordIdx] - 'a'];
	BuildTrie(node, word, wordIdx + 1);
}

void Search(vector<vector<char>> &board, Trie *node, const pair<int, int> &loc, vector<string> &result) {
	if (!node)
		return;
	if (!node->word.empty()) {
		result.emplace_back(node->word);
		node->word.clear();
	}

	char character = board[loc.first][loc.second];
	board[loc.first][loc.second] = '@';
	for (const auto &ai : axis) {
		int x = loc.first + ai[0];
		int y = loc.second + ai[1];
		if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || board[x][y] == '@')
			continue;
		Search(board, node->next[board[x][y] - 'a'], pair<int, int>(x, y), result);
	}
	board[loc.first][loc.second] = character;
}

vector<string> Solution::findWords(vector<vector<char>> &board, vector<string> &words) {
	if (board.empty() || words.empty())
		return vector<string>();

	vector<string> result;
	Trie *head = new Trie();
	for (const auto &word : words)
		BuildTrie(head, word, 0);

	for (int i = 0; i < board.size(); ++i) {
		for (int j = 0; j < board[0].size(); ++j) {
			Search(board, head->next[board[i][j] - 'a'], pair<int, int>(i, j), result);
		}
	}
	return result;
}
