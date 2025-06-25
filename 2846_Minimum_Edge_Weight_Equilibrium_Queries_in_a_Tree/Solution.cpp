#include <Solution.h>

void construct(int cur, int parent, int K, vector<int>& depth, vector<vector<int>>& up,
		vector<unordered_map<int, int>>& adj, vector<vector<vector<int>>>& cnts) {
	if (parent == -1) {
		up[cur][0] = cur;
	} else {
		up[cur][0] = parent;
		++cnts[cur][0][adj[cur][parent]];
	}

	for (int i = 1 ; i < K ; ++i) {
		up[cur][i] = up[up[cur][i-1]][i-1];
		for (int j = 1 ; j < 27 ; ++j) {
			cnts[cur][i][j] += cnts[up[cur][i-1]][i-1][j];
			cnts[cur][i][j] += cnts[cur][i-1][j];
		}
	}
	for (const auto& n : adj[cur]) {
		if (n.first == parent) continue;
		depth[n.first] = depth[cur] + 1;
		construct(n.first, cur, K, depth, up, adj, cnts);
	}
}

int findLCA(int a, int b, int K, vector<int>& depth, vector<vector<int>>& up, vector<vector<vector<int>>>& cnts, vector<int>& curCnt) {
	if (depth[a] < depth[b]) swap(a, b);

	int diff = depth[a] - depth[b];

	for (int i = 0 ; i < K ; ++i) {
		if (diff & (1 << i)) {
			for (int j = 1 ; j < 27 ; ++j) {
				curCnt[j] += cnts[a][i][j];
			}
			a = up[a][i];
		}
	}
	if (a == b) return a;
	for (int i = K - 1 ; i >= 0 ; --i) {
		if (up[a][i] != up[b][i]) {
			for (int j = 1 ; j < 27 ; ++j) {
				curCnt[j] += cnts[a][i][j];
				curCnt[j] += cnts[b][i][j];
			}
			a = up[a][i];
			b = up[b][i];
		}
	}
	for (int j = 1 ; j < 27 ; ++j) {
		curCnt[j] += cnts[a][0][j];
		curCnt[j] += cnts[b][0][j];
	}
	return up[a][0];
}

vector<int> Solution::minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
	int K = 1;
	while ((1 << K) <= n) {
		++K;
	}
	vector<int> depth(n, 0);
	vector<vector<int>> up(n, vector<int>(K, 0));
	vector<unordered_map<int, int>> adj(n, unordered_map<int, int>());
	vector<vector<vector<int>>> cnts(n, vector<vector<int>>(K, vector<int>(27, 0)));
	for (const auto& e : edges) {
		adj[e[0]][e[1]] = e[2];
		adj[e[1]][e[0]] = e[2];
	}

	construct(0, -1, K, depth, up, adj, cnts);
	vector<int> result;
	for (const auto& q : queries) {
		int a = q[0];
		int b = q[1];
		vector<int> cnt(27, 0);
		int total = 0;
		int maxCnt = 0;
		int lca = findLCA(a, b, K, depth, up, cnts, cnt);
		for (int j = 1 ; j < 27 ; ++j) {
			if (cnt[j] != 0) {
				total += cnt[j];
				maxCnt = max(maxCnt, cnt[j]);
			}
		}
		result.emplace_back(total - maxCnt);
	}
	return result;
}
