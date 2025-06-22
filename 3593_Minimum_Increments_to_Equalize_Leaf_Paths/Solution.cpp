#include <Solution.h>

void getChildCnt(int curNode, long long curCost, int parent, vector<vector<int>>& adj, vector<int>& cost, vector<long long>& leafCost) {
	if (adj[curNode].size() == 1 && adj[curNode][0] == parent) {
		leafCost[curNode] = curCost;
		return;
	}

	for (const auto& n : adj[curNode]) {
		if (n == parent) continue;
		getChildCnt(n, curCost + cost[n], curNode, adj, cost, leafCost);
		leafCost[curNode] = max(leafCost[curNode], leafCost[n]);
	}
}

void dfs(int cur, int parent, vector<long long>& leafCost, vector<vector<int>>& adj, long long maxCost, int& result) {
	if (leafCost[cur] < maxCost) {
		++result;
	}

	for (const auto& n : adj[cur]) {
		if (n == parent) continue;
		dfs(n, cur, leafCost, adj, leafCost[cur], result);
	}
}

int Solution::minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
	vector<long long> leafCost(n, 0);
	vector<vector<int>> adj(n, vector<int>());

	for (const auto& e : edges) {
		adj[e[0]].emplace_back(e[1]);
		adj[e[1]].emplace_back(e[0]);
	}

	getChildCnt(0, cost[0], -1, adj, cost, leafCost);
	int result = 0;
	dfs(0, -1, leafCost, adj, leafCost[0], result);
	return result;
}
