#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using std::cout;
using std::endl;
using std::to_string;
using std::unordered_map;

string abbrev(string &word, int i) {
	int n = word.size();
	if (n - i <= 3)
		return word;
	string result = word.substr(0, i + 1);
	result += to_string(n - i - 2);
	result.push_back(word.back());
	return result;
}

vector<string> Solution::wordsAbbreviation(vector<string> &words) {
	unordered_map<string, vector<int>> groups;

	for (int i = 0; i < words.size(); ++i) {
		if (words[i].size() < 4)
			continue;
		groups[abbrev(words[i], 0)].emplace_back(i);
	}

	for (auto &ele : groups) {
		node *root = new node();
		node *iter = root;
		for (const auto &wi : ele.second) {
			iter = root;
			for (const auto &c : words[wi]) {
				if (!iter->child[c - 'a'])
					iter->child[c - 'a'] = new node();
				iter = iter->child[c - 'a'];
				++iter->cnt;
			}
		}

		for (auto &wi : ele.second) {
			iter = root;
			int i = 0;
			for (; i < words[wi].size(); ++i) {
				if (iter->cnt == 1)
					break;
				iter = iter->child[words[wi][i] - 'a'];
			}
			words[wi] = abbrev(words[wi], i - 1);
		}
	}
	return words;
}
