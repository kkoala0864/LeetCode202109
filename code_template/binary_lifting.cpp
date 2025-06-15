#include <Solution.h>

// construct up and depth
void dfs(int cur, int parent, int K, vector<int>& depth, vector<long long>& dist,
		vector<vector<int>>& up, vector<vector<pair<int, int>>>& adj) {
	if (parent == -1) {
		up[cur][0] = cur;
	} else {
		up[cur][0] = parent;
	}

	for (int k = 1 ; k < K ; ++k) {
		up[cur][k] = up[up[cur][k-1]][k-1];
	}

	for (const auto& ad : adj[cur]) {
		if (ad.first == parent) continue;
		depth[ad.first] = depth[cur] + 1;
		dist[ad.first] = dist[cur] + ad.second;
		dfs(ad.first, cur, K, depth, dist, up, adj);
	}
}

int lca(int a, int b, vector<vector<int>>& up, vector<int>& depth, int K) {
	if (depth[a] < depth[b]) {
		swap(a, b);
	}

	int diff = depth[a] - depth[b];
	for (int i = 0 ; i < K ; ++i) {
		if (diff & (1 << i)) {
			a = up[a][i];
		}
	}
	if (a == b) return a;
	for (int i = K - 1 ; i >= 0 ; --i) {
		if (up[a][i] != up[b][i]) {
			a = up[a][i];
			b = up[b][i];
		}
	}
	return up[a][0];
}

void Solution::binaryLifting(int n, vector<vector<int>>& edges) {
	int K = 1;
	while ((1 << K) < n) {
		++K;
	}
	vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());
	for (const auto& e : edges) {
		adj[e[0]].emplace_back(pair<int, int>(e[1], e[2]));
		adj[e[1]].emplace_back(pair<int, int>(e[0], e[2]));
	}
	vector<int> depth(n, 0);
	vector<long long> dist(n, 0);
	vector<vector<int>> up(n, vector<int>(K, 0));
	dfs(0, -1, K, depth, dist, up, adj);

	// calculate distance between each node
	for (int i = 0 ; i < n ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			if (i == j) continue;
			int lcaNode = lca(i, j, up, depth, K);
			int d = dist[i] + dist[j] - 2 * dist[lcaNode];
			cout << i << " : " << j << " | " << d << endl;
		}
	}
}
