#include <Solution.h>

int dfs(int mask, int l, int r, vector<vector<int>>& adj, const string& label, vector<vector<vector<int>>>& cache) {
	if (cache[l][r][mask] != -1) return cache[l][r][mask];

	cache[l][r][mask] = 0;
	for (const auto& li : adj[l]) {
		if (mask & (1 << li)) continue;
		for (const auto& ri : adj[r]) {
			if (mask & (1 << ri)) continue;
			if (ri == li || label[li] != label[ri]) continue;
			cache[l][r][mask] = max(cache[l][r][mask], 2 + dfs(mask | 1 << li | 1 << ri, li, ri, adj, label, cache));
		}
	}
	return cache[l][r][mask];
}

int Solution::maxLen(int n, vector<vector<int>>& edges, string label) {
	vector<vector<int>> adj(n, vector<int>());
	vector<vector<vector<int>>> cache(n, vector<vector<int>>(n, vector<int>(1 << n, -1)));
	for (const auto& e : edges) {
		adj[e[0]].emplace_back(e[1]);
		adj[e[1]].emplace_back(e[0]);
	}

	int result = 1;
	for (int i = 0 ; i < n ; ++i) {
		result = max(result, 1 + dfs(1 << i, i, i, adj, label, cache));
	}
	for (const auto& e : edges) {
		if (label[e[0]] != label[e[1]]) continue;
		result = max(result, 2 + dfs(1 << e[0] | 1 << e[1], e[0], e[1], adj, label, cache));
	}
	return result;

}
