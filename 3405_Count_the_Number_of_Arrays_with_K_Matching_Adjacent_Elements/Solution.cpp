#include <Solution.h>

// construct n - k sequence which adj doesn't same
// C(n - k, k);

long long quickPow(long long x, long long n, long long mod) {
	if (n == 0) return 1;
	long long v = quickPow(x, n/2, mod);
	long long vv = v * v % mod;
	return n & 1 ? vv * x % mod : vv;
}

vector<long long> getFac(int size, long long mod) {
	vector<long long> fac(1, 1);
	for (long long i = 1 ; i <= size ; ++i) {
		fac.emplace_back((fac.back() * i) % mod);
	}
	return fac;
}

long long comb(long long m, long long n, vector<long long>& fac, long long mod) {
	if (m < n) return 0;
	if (n == m) return 1;
	long long a = fac[m];
	long long b = fac[n] * fac[m-n] % mod;
	long long inv_b = quickPow(b, mod - 2, mod);
	return a * inv_b % mod;
}

int Solution::countGoodArrays(int n, int m, int k) {
	long long mod = 1e9 + 7;

	long long baseSeq = m;
	baseSeq *= quickPow(m-1, n - k - 1, mod);
	baseSeq %= mod;
	vector<long long> fac = getFac(n, mod);
	// H(a, b) = C(a+b-1, b);
	// H(n-k, k) = C(n-k+k-1, k);
	long long ck = comb(n-1, k, fac, mod);
	long long result = baseSeq * ck % mod;
	return result;
}
/*
long long dfs(int idx, int lastValue, int n, int m, int k, long long mod, vector<unordered_map<int, unordered_map<int, long long>>>& cache) {
	if (k < 0) return 0;
	if (idx == n) {
		return k == 0;
	}
	if (cache[lastValue].count(idx) && cache[lastValue][idx].count(k)) return cache[lastValue][idx][k];

	long long cur = 0;
	for (int i = 1 ; i <= m ; ++i) {
		cur += dfs(idx + 1, i, n, m, k - (lastValue == i), mod, cache);
		cur %= mod;
	}
	return cache[lastValue][idx][k] = cur;
}

int Solution::countGoodArrays(int n, int m, int k) {
	long long result = 0;
	long long mod = 1e9 + 7;
	vector<unordered_map<int, unordered_map<int, long long>>> cache(m + 1, unordered_map<int, unordered_map<int, long long>>());
	for (int i = 1 ; i <= m ; ++i) {
		result += dfs(1, i, n, m, k, mod, cache);
		result %= mod;
	}
	return result;

}
*/
