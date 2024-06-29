#include <Solution.h>
#include <iostream>

void dfs(int start, vector<vector<int>>& od, int cur, vector<bool>& visited, vector<vector<int>>& result) {
	for (const auto& n : od[cur]) {
		if (visited[n]) continue;
		visited[n] = true;
		result[n].emplace_back(start);
		dfs(start, od, n, visited, result);
	}
}

vector<vector<int>> Solution::getAncestors(int n, vector<vector<int>>& edges) {
	vector<vector<int>> od(n, vector<int>());
	vector<vector<int>> result(n, vector<int>());

	for (const auto& e : edges) {
		od[e[0]].emplace_back(e[1]);
	}

	for (int i = 0 ; i < n ; ++i) {
		vector<bool> visited(n, false);
		visited[i] = true;
		dfs(i, od, i, visited, result);
	}

	return result;
}
