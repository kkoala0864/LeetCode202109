#include <Solution.h>
#include <iostream>
#include <unordered_set>

using std::max;
using std::min;
using std::pair;
using std::unordered_set;

struct hashFunc
{
	int operator()(const pair<int, int> &ele) const {
		return ele.first ^ ele.second;
	}
};

int dfs(vector<int> &rank, vector<vector<int>> &graph, unordered_set<pair<int, int>, hashFunc> &connDict, int node, int cRank) {
	if (rank[node] != 0)
		return rank[node];

	rank[node] = cRank;

	int minRank = cRank + 1;
	for (const auto &nb : graph[node]) {
		int nbr = rank[nb];
		if (nbr != 0 && nbr == cRank - 1)
			continue;

		int rRank = dfs(rank, graph, connDict, nb, cRank + 1);
		if (rRank <= cRank) {
			int u = min(node, nb), v = max(node, nb);
			connDict.erase({u, v});
		}

		minRank = min(minRank, rRank);
	}
	return minRank;
}

vector<vector<int>> Solution::criticalConnections(int n, vector<vector<int>> &connections) {
	vector<vector<int>> graph(n, vector<int>());
	vector<int> rank(n, 0);
	unordered_set<pair<int, int>, hashFunc> connDict;

	for (const auto &con : connections) {
		graph[con[0]].emplace_back(con[1]);
		graph[con[1]].emplace_back(con[0]);
		int u = min(con[0], con[1]), v = max(con[0], con[1]);
		connDict.insert({u, v});
	}

	dfs(rank, graph, connDict, 0, 0);

	vector<vector<int>> result;
	for (const auto &ele : connDict) {
		result.push_back({ele.first, ele.second});
	}
	return result;
}

void tarjanDFS(vector<vector<int>> &graph, vector<int> &disc, vector<int> &low, vector<vector<int>> &result, int node, int parent, int &t) {
	disc[node] = low[node] = t++;

	for (const auto &nb : graph[node]) {
		if (disc[nb] == 0)
			tarjanDFS(graph, disc, low, result, nb, node, t);
		if (nb != parent)
			low[node] = min(low[node], low[nb]);

		if (low[nb] > disc[node])
			result.push_back({node, nb});
	}
}

vector<vector<int>> Solution::Tarjan(int n, vector<vector<int>> &connections) {
	vector<vector<int>> graph(n, vector<int>());
	vector<int> disc(n, 0);
	vector<int> low(n, 0);
	vector<vector<int>> result;
	int t = 1;

	for (const auto &edge : connections) {
		graph[edge[0]].emplace_back(edge[1]);
		graph[edge[1]].emplace_back(edge[0]);
	}

	tarjanDFS(graph, disc, low, result, 0, -1, t);
	return result;
}
