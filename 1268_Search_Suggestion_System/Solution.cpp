#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::min;

vector<vector<string>> Solution::suggestedProducts(vector<string> &products, string searchWord) {
	TrieNode *root = new TrieNode(), *iter = root;

	for (const auto &p : products) {
		iter = root;
		for (const auto &c : p) {
			if (!iter->child[c - 'a'])
				iter->child[c - 'a'] = new TrieNode();
			iter = iter->child[c - 'a'];
			iter->ps.emplace(p);
		}
	}

	vector<vector<string>> result(searchWord.size(), vector<string>());
	iter = root;
	for (int idx = 0; idx < searchWord.size(); ++idx) {
		iter = iter->child[searchWord[idx] - 'a'];
		if (!iter)
			break;
		int size = min(3, (int)iter->ps.size());
		for (auto &w : iter->ps) {
			if (size <= 0)
				break;
			result[idx].emplace_back(w);
			--size;
		}
	}
	return result;
}
