#include <Solution.h>
// x / v = x * inv(v, mod - 2);

long long quickPow(long long x, long long n, long long mod) {
	if (n == 0) return 1;
	long long v = quickPow(x, n/2, mod);
	long long vv = v * v % mod;
	return n & 1 ? vv * x % mod : vv;
}

vector<int> Solution::productQueries(int n, vector<vector<int>>& queries) {
	vector<long long> powers;
	long long mod = 1e9 + 7;

	for (int i = 0 ; i < 32 ; ++i) {
		if (n & (1 << i)) {
			long long last = powers.empty() ? 1 : powers.back();
			powers.emplace_back((last * (long long)(1 << i)) % mod);
		}
	}

	vector<int> result;
	for (const auto& q : queries) {
		long long v = powers[q[1]];
		if (q[0] > 0) {
			v *= quickPow(powers[q[0] - 1], mod - 2, mod);
			v %= mod;
		}
		result.emplace_back(v);
	}
	return result;

}
