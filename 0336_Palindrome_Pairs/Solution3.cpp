#include <Solution.h>
#include <iostream>

bool isPD(const string &s, int l, int r) {
	while (l < r)
		if (s[l++] != s[r--])
			return false;
	return true;
}

vector<vector<int>> Solution::palindromePairs3(vector<string> &words) {
	Node *root = new Node();
	Node *iter = root;

	for (int wi = 0; wi < words.size(); ++wi) {
		iter = root;
		for (int ci = words[wi].size() - 1; ci >= 0; --ci) {
			if (isPD(words[wi], 0, ci))
				iter->RPList.emplace_back(wi);
			if (!iter->next[words[wi][ci] - 'a'])
				iter->next[words[wi][ci] - 'a'] = new Node();
			iter = iter->next[words[wi][ci] - 'a'];
		}
		iter->wordEnd = wi;
	}

	vector<vector<int>> result;
	for (int wi = 0; wi < words.size(); ++wi) {
		iter = root;
		for (int ci = 0; ci < words[wi].size(); ++ci) {
			if (iter->wordEnd != -1 && isPD(words[wi], ci, words[wi].size() - 1))
				result.push_back({wi, iter->wordEnd});
			iter = iter->next[words[wi][ci] - 'a'];
			if (!iter)
				break;
		}
		if (!iter)
			continue;
		if (iter->wordEnd != -1 && iter->wordEnd != wi)
			result.push_back({wi, iter->wordEnd});
		for (const auto &ri : iter->RPList)
			result.push_back({wi, ri});
	}
	return result;
}
