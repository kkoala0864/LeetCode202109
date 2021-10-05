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

string topologicalSortBFS(unordered_map<char, unordered_set<char>>& map) {
	unordered_map<char, int> indegree;
	queue<char> q;
	string result;

	for (const auto& iter: map) {
		char src = iter.first;
		for (const auto& iter : map[src]) ++indegree[iter];
	}

	for (const auto& iter: map) {
		char src = iter.first;
		if (!indegree[src]) q.emplace(src);
	}

	while (!q.empty()) {
		char cur = q.front();
		q.pop();
		result += cur;

		for (const auto& neighbor : map[cur]) {
			--indegree[neighbor];
			if (!indegree[neighbor]) q.emplace(neighbor);
		}
	}
	return result.size() < map.size() ? "" : result;
}

string Solution::alienOrder(vector<string>& words) {
	unordered_map<char, unordered_set<char>> map;

	for (const auto& word : words) {
		for (const auto& ch : word) {
			map[ch] = unordered_set<char>();
		}
	}

	for (int i = 0 ; i < words.size() ; ++i) {
		string lhs = words[i];
		for (int j = i + 1 ; j < words.size() ; ++j) {
			string rhs = words[j];
			int size = min(lhs.size(), rhs.size());
			if (lhs.size() > rhs.size() && lhs.substr(0, size) == rhs) return "";
			for (int k = 0 ; k < size ; ++k) {
				if (lhs[k] == rhs[k]) continue;
				map[lhs[k]].emplace(rhs[k]);
				break;
			}
		}
	}
	return topologicalSortBFS(map);
}
