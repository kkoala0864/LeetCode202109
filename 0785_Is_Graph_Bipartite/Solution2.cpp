#include <Solution.h>
#include <iostream>

bool dfs2(vector<vector<int>> &edge, vector<int> &group, int idx, int color) {
	if (group[idx] != 0)
		return group[idx] == color;

	group[idx] = color;

	for (const auto &n : edge[idx]) {
		if (!dfs2(edge, group, n, color == 1 ? 2 : 1))
			return false;
	}
	return true;
}

bool Solution::isBipartite2(vector<vector<int>> &graph) {
	vector<vector<int>> edge(graph.size(), vector<int>());

	vector<int> group(graph.size(), 0);
	for (int i = 0; i < graph.size(); ++i) {
		for (const auto &e : graph[i]) {
			edge[i].emplace_back(e);
			edge[e].emplace_back(i);
		}
	}

	for (int i = 0; i < graph.size(); ++i) {
		if (group[i] != 0)
			continue;
		if (!dfs2(edge, group, i, 1))
			return false;
	}
	return true;
}
