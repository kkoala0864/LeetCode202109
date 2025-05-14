#include <Solution.h>

vector<vector<long long>> matMulti(vector<vector<long long>>& a, vector<vector<long long>>& b, long long mod) {
	vector<vector<long long>> ret(26, vector<long long>(26, 0));

	for (int i = 0 ; i < 26 ; ++i) {
		for (int j = 0 ; j < 26 ; ++j) {
			if (a[i][j] == 0) continue;
			for (int k = 0 ; k < 26 ; ++k) {
				ret[i][k] += (a[i][j] * b[j][k]);
				ret[i][k] %= mod;
			}
		}
	}
	return ret;
}

vector<vector<long long>> matPow(vector<vector<long long>>& x, int n, long long mod) {
	vector<vector<long long>> result(26, vector<long long>(26, 0));
	for (int i = 0 ; i < 26 ; ++i) result[i][i] = 1;
	if (n == 0) return result;

	auto v = matPow(x, n >> 1, mod);
	auto vv = matMulti(v, v, mod);
	return n & 1 ? matMulti(vv, x, mod) : vv;
}

int Solution::lengthAfterTransformations(string s, int t, vector<int>& nums) {
	long long mod = 1e9 + 7;

	vector<vector<long long>> M(26, vector<long long>(26, 0));
	for (int i = 0 ; i < 26 ; ++i) {
		for (int j = 1 ; j <= nums[i] ; ++j) {
			int idx = (i + j) % 26;
			++M[i][idx];
			M[i][idx] %= mod;
		}
	}

	auto Mt = matPow(M, t, mod);

	vector<int> fac(26, 0);
	for (const auto& c : s) ++fac[c-'a'];

	long long result = 0;
	for (int i = 0 ; i < 26 ; ++i) {
		long long sum = 0;
		for (int j = 0 ; j < 26 ; ++j) {
			sum += Mt[i][j];
			sum %= mod;
		}
		result += (sum * fac[i]);
		result %= mod;
	}
	return result;
}
