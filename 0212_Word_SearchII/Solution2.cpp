#include <Solution.h>
#include <iostream>

void BuildTree(Trie* node, const string& word) {
	for (const auto& ch : word) {
		if (!node->next[ch-'a']) node->next[ch-'a'] = new Trie();
		node = node->next[ch-'a'];
	}
	node->word = word;
}

vector<vector<int>> axiss = {{1,0}, {0,1},{0,-1}, {-1,0}};

void traverse(vector<vector<char>>& board, Trie* node, int i, int j, vector<string>& result) {
	if (!node) return;
	if (node->word != "") {
		result.emplace_back(node->word);
		node->word = "";
	}

	char tmpChar = board[i][j];
	board[i][j] = '@';
	for (const auto& ai : axiss) {
		int x = i + ai[0];
		int y = j + ai[1];
		if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && board[x][y] != '@') {
			if (node->next[board[x][y]-'a']) {
				traverse(board, node->next[board[x][y]-'a'], x, y, result);
			}
		}
	}
	board[i][j] = tmpChar;
}

vector<string> Solution::findWords2(vector<vector<char>>& board, vector<string>& words) {
	if (board.empty() || words.empty()) return vector<string>();
	Trie* root = new Trie();
	for (const auto& word : words) BuildTree(root, word);

	vector<string> result;
	for (int i = 0 ; i < board.size() ; ++i) {
		for (int j = 0 ; j < board[0].size() ; ++j) {
			traverse(board, root->next[board[i][j]-'a'], i, j, result);
		}
	}
	return result;
}
