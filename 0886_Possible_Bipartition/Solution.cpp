#include <Solution.h>
#include <iostream>

bool dfs(vector<vector<int>>& graph, vector<int>& group, int i, int mark) {
	if (group[i] != 0) return group[i] == mark;
	if (group[i] == 0) group[i] = mark;
	for (const auto& v : graph[i]) {
		if (!dfs(graph, group, v, mark == 1 ? 2 : 1)) return false;
	}
	return true;
}

bool Solution::possibleBipartition(int n, vector<vector<int>>& dislikes) {
	vector<int> group(n+1, 0);
	vector<vector<int>> graph(n+1, vector<int>());
	for (const auto& d : dislikes) {
		graph[d[0]].emplace_back(d[1]);
		graph[d[1]].emplace_back(d[0]);
	}

	for (int i = 0 ; i < n ; ++i) {
		if (graph[i].empty()) continue;
		if (!dfs(graph, group, i, group[i] == 0 ? 1 : group[i])) return false;
	}
	return true;
}
