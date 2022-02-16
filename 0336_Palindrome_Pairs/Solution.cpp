#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::reverse;

bool hasPalinRemain(const string& s, int i) {
	int start = i;
	int end = s.size() - 1;
	while (start < end) {
		if (s[start++] != s[end--]) return false;
	}
	return true;
}

vector<vector<int>> Solution::palindromePairs(vector<string>& words) {
	Node* root = new Node();
	for (int i = 0 ; i < words.size() ; ++i) {
		string s = words[i];
		reverse(s.begin(), s.end());
		Node* iter = root;
		for (int j = 0 ; j < s.size() ; ++j) {
			if (hasPalinRemain(s, j)) {
				iter->RPList.emplace_back(i);
			}
			int idx = s[j] - 'a';
			if (!iter->next[idx]) iter->next[idx] = new Node();
			iter = iter->next[idx];
		}
		iter->wordEnd = i;
	}

	vector<vector<int>> result;
	for (int i = 0 ; i < words.size() ; ++i) {
		string s = words[i];
		Node* iter = root;
		for (int j = 0 ; j < s.size() ; ++j) {
			if (iter->wordEnd != -1 && hasPalinRemain(s, j)) {
				result.push_back({i, iter->wordEnd});
			}
			iter = iter->next[s[j] - 'a'];
			if (!iter) break;
		}

		if (!iter) continue;
		if (iter->wordEnd != -1 && iter->wordEnd != i) result.push_back({i, iter->wordEnd});
		for (auto& idx : iter->RPList) result.push_back({i, idx});
	}
	return result;
}
