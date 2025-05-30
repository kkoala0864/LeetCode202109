#include <Solution.h>

void dfs(int lastNode, int curNode, vector<vector<int>>& connect, int level, int& maxDepth) {
	int cnt = 0;
	for (const auto& n : connect[curNode]) {
		if (n == lastNode) continue;
		++cnt;
		dfs(curNode, n, connect, level + 1, maxDepth);
	}
	if (cnt == 0) {
		maxDepth = max(maxDepth, level);
		return;
	}
}

vector<long long> getFac(int size, long long mod) {
	vector<long long> fac(1, 1);

	for (long long i = 1 ; i <= size ; ++i) {
		fac.emplace_back((fac.back() * i) % mod);
	}
	return fac;
}

long long quickPow(long long k, long long n, long long mod) {
	if (n == 0) return 1;

	long long v = quickPow(k, n / 2, mod);
	long long vv = (v * v) % mod;
	return n & 1 ? vv * k % mod : vv;
}

long long comb(int m, int n, vector<long long>& fac, long long mod) {
	if (m < n) return 0;
	if (m == n) return 1;
	n = min(m-n, n);

	long long a = fac[m];
	long long b = fac[n] * fac[m-n] % mod;
	long long inv_b = quickPow(b, mod - 2, mod);
	return a * inv_b % mod;
}

int Solution::assignEdgeWeights(vector<vector<int>>& edges) {
	vector<vector<int>> connect(edges.size() + 2, vector<int>());
	for (const auto& e : edges) {
		connect[e[0]].emplace_back(e[1]);
		connect[e[1]].emplace_back(e[0]);
	}

	int maxDepth = 0;
	long long mod = 1e9 + 7;
	dfs(-1, 1, connect, 0, maxDepth);
	auto fac = getFac(maxDepth, mod);

	long long result = 0;
	for (int i = 1 ; i <= maxDepth ; i += 2) {
		int v = comb(maxDepth, i, fac, mod);
		result += v;
		result %= mod;
	}
	return result;
}
