#include <Solution.h>
#include <iostream>

void dfs3(vector<vector<int>>& graph, int idx, vector<bool>& visited, vector<int>& local, vector<vector<int>>& result) {
	if (idx == graph.size() - 1) {
		result.emplace_back(local);
		return;
	}

	for (const auto& n : graph[idx]) {
		if (visited[n]) continue;
		visited[n] = true;
		local.emplace_back(n);
		dfs3(graph, n, visited, local, result);
		visited[n] = false;
		local.pop_back();
	}
}

vector<vector<int>> Solution::allPathsSourceTarget3(vector<vector<int>>& graph) {
	vector<vector<int>> result;
	vector<int> local(1, 0);
	vector<bool> visited(graph.size(), false);
	visited[0] = true;
	dfs3(graph, 0, visited, local, result);
	return result;
}
