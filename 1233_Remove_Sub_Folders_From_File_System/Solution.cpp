#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;
using std::cout;
using std::endl;

vector<string> split(const string& str) {
	vector<string> result;
	string cur;
	for (int i = 0 ; i < str.size() ; ++i) {
		if (str[i] == '/') {
			if (!cur.empty()) result.emplace_back(cur);
			cur.clear();
		} else {
			cur.push_back(str[i]);
		}
	}
	if (!cur.empty()) {
		result.emplace_back(cur);
	}
	return result;
}

vector<string> Solution::removeSubfolders(vector<string>& folder) {
	auto cmp = [](const string& lhs, const string& rhs) {
		return lhs.size() == rhs.size() ? lhs < rhs : lhs.size() < rhs.size();
	};

	sort(folder.begin(), folder.end(), cmp);

	Trie* root = new Trie();
	Trie* iter = nullptr;
	vector<string> result;

	for (const auto& f : folder) {
		auto s = split(f);
		iter = root;
		for (const auto& i : s) {
			if (iter->child.count(i) == 0) iter->child[i] = new Trie();
			iter = iter->child[i];
			if (iter->isEnd) {
				break;
			}
		}
		if (!iter->isEnd) {
			iter->isEnd = true;
			result.emplace_back(f);
		}
	}
	return result;
}
