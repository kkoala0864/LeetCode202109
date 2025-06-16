#include <Solution.h>

int dfs(int cur, int parent, unordered_map<int, unordered_set<int>>& gm, vector<vector<int>>& adj) {
	int curCnt = 0;

	for (const auto& n : adj[cur]) {
		if (n == parent) continue;
		curCnt += dfs(n, cur, gm, adj);
		if (gm[cur].count(n)) ++curCnt;
	}
	return curCnt;
}

void reroot(int cur, int parent, unordered_map<int, unordered_set<int>>& gm, vector<vector<int>>& adj, int k, int count, int& result) {
	if (count >= k) ++result;

	for (const auto& n : adj[cur]) {
		if (n == parent) continue;
		int tmp = count;
		if (gm[cur].count(n)) {
			--tmp;
		}
		if (gm[n].count(cur)) {
			++tmp;
		}
		reroot(n, cur, gm, adj, k, tmp, result);
	}
}

int Solution::rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
	int size = edges.size() + 1;
	vector<vector<int>> adj(size, vector<int>());
	for (const auto& e : edges) {
		adj[e[0]].emplace_back(e[1]);
		adj[e[1]].emplace_back(e[0]);
	}

	unordered_map<int, unordered_set<int>> gm;
	for (const auto& g : guesses) {
		gm[g[0]].emplace(g[1]);
	}

	int count = dfs(0, -1, gm, adj);

	int result = 0;
	reroot(0, -1, gm, adj, k, count, result);
	return result;
}
