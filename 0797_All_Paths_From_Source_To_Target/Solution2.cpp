#include <Solution.h>
#include <iostream>
using std::cout;
using std::endl;

void dfs(vector<vector<int>> &graph, int idx, vector<bool> &visited, vector<int> &local, vector<vector<int>> &result) {
	if (idx == graph.size() - 1) {
		result.emplace_back(local);
		return;
	}

	for (const auto &v : graph[idx]) {
		if (visited[v])
			continue;
		visited[idx] = true;
		local.emplace_back(v);
		dfs(graph, v, visited, local, result);
		visited[idx] = false;
		local.pop_back();
	}
}

vector<vector<int>> Solution::allPathsSourceTarget2(vector<vector<int>> &graph) {
	vector<vector<int>> result;
	vector<int> local(1, 0);
	vector<bool> visited(graph.size(), false);
	visited[0] = true;
	dfs(graph, 0, visited, local, result);
	return result;
}
