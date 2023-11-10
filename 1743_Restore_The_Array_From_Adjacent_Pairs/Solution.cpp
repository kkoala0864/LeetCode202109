#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

void dfs(int from, int cur, unordered_map<int, vector<int>>& m, vector<int>& result) {
	result.emplace_back(cur);

	while (!m[cur].empty()) {
		int next = m[cur].back();
		m[cur].pop_back();
		if (next == from) continue;
		dfs(cur, next, m, result);
	}
}

vector<int> Solution::restoreArray(vector<vector<int>>& adjacentPairs) {
	if (adjacentPairs.size() == 1) return adjacentPairs[0];
	unordered_map<int, vector<int>> m;

	for (const auto& a : adjacentPairs) {
		m[a[0]].emplace_back(a[1]);
		m[a[1]].emplace_back(a[0]);
	}

	int start = -1;
	for (const auto& e : m) {
		if (e.second.size() > 1) continue;
		start = e.first;
	}

	vector<int> result;

	dfs(-1, start, m, result);
	return result;
}
