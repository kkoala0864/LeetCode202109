#include <Solution.h>

bool check(const string& s, int start, int end, Trie* root) {
	auto iter = root;
	for (int i = start ; i <= end ; ++i) {
		if (!iter->child[s[i] - 'a']) return true;
		iter = iter->child[s[i]- 'a'];
		if (iter->isEnd) return false;
	}
	return !iter->isEnd;
}

int Solution::longestValidSubstring(string word, vector<string>& forbidden) {
	Trie* root = new Trie();

	for (const auto& f : forbidden) {
		auto iter = root;
		for (const auto& c : f) {
			if (!iter->child[c - 'a']) iter->child[c-'a'] = new Trie();
			iter = iter->child[c-'a'];
		}
		iter->isEnd = true;
	}

	int result = 0;

	int r = word.size() - 1;
	for (int i = word.size() - 1 ; i >= 0 ; --i) {
		while (r >= i && !check(word, i, r, root)) {
			--r;
		}
		result = max(result, r - i + 1);
	}
	return result;
}
