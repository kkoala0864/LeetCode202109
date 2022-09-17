#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::reverse;

bool isPalindrome(const string& s, int l, int r) {
	while (l < r) if (s[l++] != s[r--]) return false;
	return true;
}

vector<vector<int>> Solution::palindromePairs2(vector<string>& words) {
	Node* root = new Node();

	for (int wi = 0 ; wi < words.size() ; ++wi) {
		Node* iter = root;
		for (int i = words[wi].size() - 1 ; i >= 0 ; --i) {
			if (isPalindrome(words[wi], 0, i)) iter->RPList.emplace_back(wi);
			if (!iter->next[words[wi][i]-'a']) iter->next[words[wi][i]-'a'] = new Node();
			iter = iter->next[words[wi][i]-'a'];
		}
		iter->wordEnd = wi;
	}

	vector<vector<int>> result;
	Node* iter = root;
	for (int i = 0 ; i < words.size() ; ++i) {
		iter = root;
		for (int j = 0 ; j < words[i].size() ; ++j) {
			if(iter->wordEnd != -1 && isPalindrome(words[i], j, words[i].size()-1)) {
				result.push_back({i, iter->wordEnd});
			}
			iter = iter->next[words[i][j]-'a'];
			if (!iter) break;
		}
		if (!iter) continue;
		if (iter->wordEnd != -1 && i != iter->wordEnd) result.push_back({i, iter->wordEnd});
		for (const auto& idx : iter->RPList) result.push_back({i, idx});
	}
	return result;
}
