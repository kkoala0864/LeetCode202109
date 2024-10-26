#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;

vector<string> Solution::removeSubfolders(vector<string>& folder) {
	auto cmp = [](const string& lhs, const string& rhs) {
		return lhs.size() == rhs.size() ? lhs < rhs : lhs.size() < rhs.size();
	};

	sort(folder.begin(), folder.end(), cmp);

	Trie* root = new Trie();
	Trie* iter = nullptr;
	vector<string> result;

	for (auto& f : folder) {
		iter = root;
		f.push_back('/');
		for (const auto& i : f) {
			int idx = i == '/' ? 26 : i - 'a';
			if (!iter->child[idx]) iter->child[idx] = new Trie();
			iter = iter->child[idx];
			if (iter->isEnd) {
				break;
			}
		}
		if (!iter->isEnd) {
			iter->isEnd = true;
			f.pop_back();
			result.emplace_back(f);
		}
	}
	return result;
}
