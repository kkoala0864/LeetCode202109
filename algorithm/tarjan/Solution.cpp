#include <Solution.h>
#include <iostream>

using std::min;

void tarjanDFS(vector<vector<int>>& graph, vector<int>& disc, vector<int>& low, vector<vector<int>>& result, int node, int parent, int& t) {
	disc[node] = low[node] = t++;

	for (const auto& nb : graph[node]) {
		if (disc[nb] == 0) tarjanDFS(graph, disc, low, result, nb, node, t);
		if (nb != parent) low[node] = min(low[node], low[nb]);

		if (low[nb] > disc[node]) result.push_back({node, nb});
	}
}

vector<vector<int>> Solution::Tarjan(int n, vector<vector<int>>& connections) {
	vector<vector<int>> graph(n, vector<int>());
	vector<int> disc(n, 0);
	vector<int> low(n, 0);
	vector<vector<int>> result;
	int t = 1;

	for (const auto& edge : connections) {
		graph[edge[0]].emplace_back(edge[1]);
		graph[edge[1]].emplace_back(edge[0]);
	}

	tarjanDFS(graph, disc, low, result, 0, -1, t);
	return result;
}
