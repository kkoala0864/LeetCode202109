#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

void getWord(TrieNode *node, int &k, string &local, vector<string> &result) {
	if (!node || k == 0)
		return;

	if (node->isEnd) {
		result.emplace_back(local);
		--k;
	}

	for (int i = 0; i < 26; ++i) {
		if (node->next[i]) {
			local.push_back(i + 'a');
			getWord(node->next[i], k, local, result);
			local.pop_back();
		}
	}
}

vector<string> Solution::topKFrequent2(vector<string> &words, int k) {
	unordered_map<string, int> freqCnt;
	for (const auto &w : words)
		++freqCnt[w];

	vector<TrieNode *> freqTrie(words.size() + 1, nullptr);

	for (const auto &fc : freqCnt) {
		if (!freqTrie[fc.second])
			freqTrie[fc.second] = new TrieNode();
		auto node = freqTrie[fc.second];

		for (const auto &c : fc.first) {
			if (!node->next[c - 'a'])
				node->next[c - 'a'] = new TrieNode();
			node = node->next[c - 'a'];
		}
		node->isEnd = true;
	}

	vector<string> result;
	string local;
	for (int i = freqTrie.size() - 1; i >= 1; --i)
		getWord(freqTrie[i], k, local, result);
	return result;
}
