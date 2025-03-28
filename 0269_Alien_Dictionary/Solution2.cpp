#include <Solution.h>
#include <iostream>
#include <unordered_set>
#include <queue>
#include <algorithm>

using std::min;
using std::queue;
using std::unordered_set;

string Solution::alienOrder2(vector<string> &words) {
	vector<unordered_set<int>> od(26, unordered_set<int>());

	vector<int> icnt(26, 0);
	unordered_set<int> us;

	for (int i = 0; i < words.size(); ++i) {
		for (const auto &c : words[i])
			us.emplace(c - 'a');
		for (int j = i + 1; j < words.size(); ++j) {
			int size = min(words[i].size(), words[j].size());
			if (words[i].size() > words[j].size() && words[i].substr(0, size) == words[j])
				return "";
			for (int k = 0; k < size; ++k) {
				if (words[i][k] == words[j][k])
					continue;
				if (od[words[i][k] - 'a'].count(words[j][k] - 'a'))
					break;
				od[words[i][k] - 'a'].emplace(words[j][k] - 'a');
				++icnt[words[j][k] - 'a'];
				break;
			}
		}
	}

	queue<int> que;
	string result;
	for (int i = 0; i < 26; ++i) {
		if (us.count(i) == 0)
			continue;
		if (icnt[i] == 0)
			que.emplace(i);
	}

	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		result.push_back(cur + 'a');
		us.erase(cur);

		for (const auto &c : od[cur]) {
			--icnt[c];
			if (icnt[c] == 0)
				que.emplace(c);
		}
	}
	return us.empty() ? result : "";
}
