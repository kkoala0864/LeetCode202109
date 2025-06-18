#include <Solution.h>

void construct(int cur, int parent, int curW, int K, vector<unordered_map<int, long long>>& adj,
		vector<int>& depth, vector<long long>& dist, vector<vector<int>>& up, vector<vector<long long>>& w) {
	if (parent == -1) {
		up[cur][0] = cur;
	} else {
		up[cur][0] = parent;
		w[cur][0] = curW;
	}

	for (int i = 1 ; i < K ; ++i) {
		up[cur][i] = up[up[cur][i-1]][i-1];
		w[cur][i] = w[cur][i-1] + w[up[cur][i-1]][i-1];
	}

	for (const auto& n : adj[cur]) {
		if (n.first == parent) continue;
		depth[n.first] = depth[cur] + 1;
		dist[n.first] = dist[cur] + n.second;
		construct(n.first, cur, n.second, K, adj, depth, dist, up, w);
	}
}

int findLCA(int a, int b, int K, vector<int>& depth, vector<vector<int>>& up) {
	if (depth[a] < depth[b]) swap(a, b);

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

vector<int> Solution::findMedian(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
	vector<unordered_map<int, long long>> adj(n, unordered_map<int, long long>());

	for (const auto& e : edges) {
		adj[e[0]][e[1]] = e[2];
		adj[e[1]][e[0]] = e[2];
	}

	int K = 1;
	while ((1 << K) <= n) {
		++K;
	}
	vector<int> depth(n, 0);
	vector<vector<int>> up(n, vector<int>(K, -1));
	vector<long long> dist(n, 0);
	vector<vector<long long>> w(n, vector<long long>(K, 0));

	construct(0, -1, 0, K, adj, depth, dist, up, w);

	vector<int> result;
	for (const auto& q : queries) {
		int a = q[0];
		int b = q[1];
		int lca = findLCA(a, b, K, depth, up);
		long long distAll = dist[a] + dist[b] - 2 * dist[lca];
		long long target = (distAll + 1) >> 1;
		long long preDist = dist[a] - dist[lca];

		if (preDist == target) result.emplace_back(lca);
		else if (preDist > target) {
			long long cur = 0;
			int curNode = a;
			for (int i = K - 1 ; i >= 0 ; --i) {
				if (cur + w[curNode][i] < target) {
					cur += w[curNode][i];
					curNode = up[curNode][i];
				}
			}
			result.emplace_back(up[curNode][0]);
		} else {
			long long cur = 0;
			int curNode = b;
			target = dist[b] - dist[lca] - target;
			for (int i = K - 1 ; i >= 0 ; --i) {
				if (cur + w[curNode][i] <= target) {
					cur += w[curNode][i];
					curNode = up[curNode][i];
				}
			}
			result.emplace_back(curNode);
		}
	}
	return result;
}
