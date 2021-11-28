#include <Solution.h>
#include <iostream>

void traverse(vector<vector<int>>& graph, int cur, vector<int>& local, vector<vector<int>>& result) {
	if (cur == graph.size() - 1) {
		result.emplace_back(local);
		return;
	}

	for (int i = 0 ; i < graph[cur].size() ; ++i) {
		local.emplace_back(graph[cur][i]);
		traverse(graph, graph[cur][i], local, result);
		local.pop_back();
	}
}

vector<vector<int>> Solution::allPathsSourceTarget(vector<vector<int>>& graph) {
	vector<vector<int>> result;
	vector<int> local(1, 0);
	traverse(graph, 0, local, result);
	return result;
}
