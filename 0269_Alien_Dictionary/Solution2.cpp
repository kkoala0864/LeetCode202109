#include <Solution.h>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <algorithm>

using std::unordered_set;
using std::unordered_map;
using std::queue;
using std::min;

string topologicalSortBFS2(unordered_map<char, unordered_set<char>>& uMap) {
	unordered_map<char, int> indegree;
	queue<char> que;
	string result;

	for (const auto& iter : uMap) {
		char src = iter.first;
		for (const auto& iter : uMap[src]) ++indegree[iter];
	}

	for (const auto& iter : uMap) {
		char ch = iter.first;
		if (indegree[ch] == 0) que.emplace(ch);
	}

	while (!que.empty()) {
		char ch = que.front();
		que.pop();
		result.push_back(ch);

		for (const auto& iter : uMap[ch]) {
			--indegree[iter];
			if (indegree[iter] == 0) que.emplace(iter);
		}
	}
	return result.size() < uMap.size() ? "" : result;
}

string Solution::alienOrder2(vector<string>& words) {
	unordered_map<char, unordered_set<char>> uMap;
	for (const auto& word : words) {
		for (const auto& ch : word) {
			uMap[ch] = unordered_set<char>();
		}
	}

	for (int i = 0 ; i < words.size () ; ++i) {
		string lhs = words[i];
		for (int j = i + 1 ; j < words.size() ; ++j) {
			string rhs = words[j];
			int size = min(lhs.size(), rhs.size());
			if (lhs.size() > rhs.size() && lhs.substr(0, size) == rhs) return "";
			for (int k = 0 ; k < size ; ++k) {
				if (lhs[k] == rhs[k]) continue;
				uMap[lhs[k]].emplace(rhs[k]);
				break;
			}
		}
	}
	return topologicalSortBFS2(uMap);
}
