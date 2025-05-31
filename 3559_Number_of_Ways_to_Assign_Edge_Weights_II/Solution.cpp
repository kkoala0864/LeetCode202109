#include <Solution.h>

void dfs(int cur, int parent, vector<vector<int>>& connect, vector<vector<int>>& ancestor, vector<int>& depth, int LOG) {
	if (parent == -1) {
		ancestor[cur][0] = cur;
	} else {
		ancestor[cur][0] = parent;
	}

	for (int i = 1 ; i < LOG ; ++i) {
		ancestor[cur][i] = ancestor[ancestor[cur][i-1]][i-1];
	}

	for (const auto& n : connect[cur]) {
		if (n == parent) continue;
		depth[n] = depth[cur] + 1;
		dfs(n, cur, connect, ancestor, depth, LOG);
	}
}

int LCA(int a, int b, vector<int>& depth, vector<vector<int>>& ancestor, int LOG) {
	if (depth[a] < depth[b]) swap(a, b);
	int diff = depth[a] - depth[b];
	int bi = 0;
	while ((1 << bi) <= diff) {
		if (diff & (1 << bi)) a = ancestor[a][bi];
		++bi;
	}

	if (a == b) return a;

	for (int i = LOG - 1 ; i >= 0 ; --i) {
		if (ancestor[a][i] != ancestor[b][i]) {
			a = ancestor[a][i];
			b = ancestor[b][i];
		}
	}
	return ancestor[a][0];
}

vector<long long> getFac(int size, long long mod) {
	vector<long long> fac(1, 1);
	for (long long i = 1 ; i <= size ; ++i) {
		fac.emplace_back((fac.back() * i) % mod);
	}
	return fac;
}

long long quickPow(long long x, long long n, long long mod) {
	if (n == 0) return 1;

	long long v = quickPow(x, n / 2, mod);
	long long vv = v * v % mod;
	return n & 1 ? vv * x % mod : vv;
}

long long comb(int m, int n, vector<long long>& fac, long long mod, unordered_map<int, unordered_map<int, long long>>& cache) {
	n = min(n, m - n);
	if (n == 0) return 1;
	if (cache.count(m) && cache[m].count(n)) return cache[m][n];

	long long a = fac[m];
	long long b = fac[n] * fac[m-n] % mod;
	long long inv_b = quickPow(b, mod - 2, mod);
	return cache[m][n] = a * inv_b % mod;
}

vector<int> Solution::assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
	int size = edges.size() + 1;
	vector<vector<int>> connect(size + 1, vector<int>());
	for (const auto& e : edges) {
		connect[e[0]].emplace_back(e[1]);
		connect[e[1]].emplace_back(e[0]);
	}

	long long mod = 1e9 + 7;
	vector<long long> fac = getFac(size, mod);
	float log = log2(connect.size());
	int LOG = log + 1;
	vector<vector<int>> ancestor(size + 1, vector<int>(LOG, 0));
	vector<int> depth(size + 1, 0);
	dfs(1, -1, connect, ancestor, depth, LOG);
	unordered_map<int, unordered_map<int, long long>> cache;
	unordered_map<int, long long> distCache;

	vector<int> result;
	for (const auto& q : queries) {
		if (q[0] == q[1]) {
			result.emplace_back(0);
			continue;
		}
		int lca = LCA(q[0], q[1], depth, ancestor, LOG);
		int dist = depth[q[0]] + depth[q[1]] - (2 * depth[lca]);
		if (distCache.count(dist) == 0) {
			long long cur = 0;
			for (int i = 1 ; i <= dist ; i += 2) {
				cur += comb(dist, i, fac, mod, cache);
				cur %= mod;
			}
			distCache[dist] = cur;
		}
		result.emplace_back(distCache[dist]);
	}
	return result;
}
