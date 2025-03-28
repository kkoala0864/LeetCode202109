#include <Solution.h>
#include <iostream>

bool dfs(vector<vector<int>> &graph, vector<int> &group, int node, int idx) {
	if (group[node] != 0)
		return group[node] == idx;
	if (group[node] == 0)
		group[node] = idx;
	for (auto &iter : graph[node]) {
		if (!dfs(graph, group, iter, idx == 1 ? 2 : 1))
			return false;
	}
	return true;
}

bool Solution::isBipartite(vector<vector<int>> &graph) {
	vector<int> group(graph.size(), 0);
	for (int i = 0; i < graph.size(); ++i) {
		if (graph[i].empty())
			continue;
		if (!dfs(graph, group, i, group[i] == 0 ? 1 : group[i]))
			return false;
	}
	return true;
}
