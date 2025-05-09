#include <Solution.h>

long long quickPow(long long x, long long n, long long mod) {
	if (n == 0) return 1;
	long long v = quickPow(x, n / 2, mod);
	long long vv = v * v % mod;
	return n & 1 ? vv * x % mod : vv;
}

void getFac(int size, long long mod, vector<long long>& f, vector<long long>& invf) {
	f.emplace_back(1);
	invf.emplace_back(1);

	for (long long i = 1 ; i <= size ; ++i) {
		f.emplace_back((f.back() * i) % mod);
		invf.emplace_back(quickPow(f.back(), mod - 2, mod) % mod);
	}
}

long long comb(long long m, long long n, long long mod, vector<long long>& f, vector<long long>& invf) {
	return f[m] * invf[n] % mod * invf[m-n] % mod;
}

long long dfs(long long idx, long long sum, long long preSize, long long postSize, vector<int>& cnt,
		vector<long long>& f, vector<long long>& invf, long long& mod, unordered_map<long long, long long>&m,
		unordered_map<int, unordered_map<int, long long>>& combCache) {
	if (idx == 10) {
		return (sum | preSize | postSize) == 0 ? 1 : 0;
	}

	if (preSize == 0 && sum) {
		return 0;
	}

	long long key = (idx << 40) | (preSize << 20) | sum;
	if (m.count(key)) return m[key];

	long long result = 0;
	for (long long i = 0 ; i <= min(preSize, (long long)cnt[idx]) ; ++i) {
		int rest = min((long long)cnt[idx] - i, postSize);
		if (i * idx > sum) break;
		result += (comb(preSize, i, mod, f, invf) * comb(postSize, rest, mod, f, invf) % mod
				* dfs(idx + 1, sum - (idx * i), preSize - i, postSize - rest, cnt, f, invf, mod, m, combCache) % mod);
		result %= mod;

	}
	return m[key] = result;
}

int Solution::countBalancedPermutations(string num) {
	int sum = 0;
	vector<int> tCnt(10, 0);
	for (const auto& v : num) {
		++tCnt[v - '0'];
		sum += v - '0';
	}
	if (sum & 1) return 0;

	int target = sum >> 1;
	int k = num.size() / 2;

	long long mod = 1e9 + 7;
	vector<long long> f, invf;
	getFac(num.size(), mod, f, invf);
	unordered_map<long long, long long> m;
	unordered_map<int, unordered_map<int, long long>> combCache;
	return dfs(0, target, k, num.size() - k, tCnt, f, invf, mod, m, combCache);
}
