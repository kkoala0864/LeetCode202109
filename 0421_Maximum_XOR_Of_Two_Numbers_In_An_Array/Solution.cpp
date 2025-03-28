#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

void addNode(int num, TrieNode *node) {
	TrieNode *iter = node;
	for (int i = 31; i >= 0; --i) {
		int bit = (num >> i) & 1;
		if (!iter->next[bit])
			iter->next[bit] = new TrieNode();
		iter = iter->next[bit];
	}
}

int findMax(int num, TrieNode *node) {
	TrieNode *iter = node;
	int result = 0;
	for (int i = 31; i >= 0; --i) {
		int bit = (num >> i) & 1;
		if (iter->next[1 - bit]) {
			result += (1 << i);
			iter = iter->next[1 - bit];
		} else {
			iter = iter->next[bit];
		}
	}
	return result;
}

int Solution::findMaximumXOR(vector<int> &nums) {
	TrieNode *root = new TrieNode();
	for (const auto &iter : nums)
		addNode(iter, root);

	int result = 0;
	for (const auto &iter : nums) {
		result = max(result, findMax(iter, root));
	}
	return result;
}
