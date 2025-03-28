#include <Solution.h>
#include <iostream>

void dfs(TrieNode *iter, int cnt, int &result) {
	if (!iter)
		return;
	bool find = false;
	for (int i = 0; i < 26; ++i) {
		if (iter->child[i]) {
			find = true;
			dfs(iter->child[i], cnt + 1, result);
		}
	}
	if (!find)
		result += cnt;
}

int Solution::minimumLengthEncoding(vector<string> &words) {
	TrieNode *root = new TrieNode();
	TrieNode *iter = root;

	for (const auto &w : words) {
		iter = root;
		for (int i = w.size() - 1; i >= 0; --i) {
			if (!iter->child[w[i] - 'a'])
				iter->child[w[i] - 'a'] = new TrieNode();
			iter = iter->child[w[i] - 'a'];
		}
	}

	int result = 0;
	dfs(root, 1, result);
	return result;
}
