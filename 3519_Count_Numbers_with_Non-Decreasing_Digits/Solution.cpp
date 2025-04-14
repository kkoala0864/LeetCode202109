#include <Solution.h>
#include <iostream>
#include <vector>

void minusOne(string &l) {
	int carry = -1;
	for (int i = l.size() - 1; i >= 0; --i) {
		if (carry == 0)
			break;
		if (l[i] == '0') {
			l[i] = '9';
		} else {
			--l[i];
			carry = 0;
		}
	}
	auto pos = l.find_first_not_of('0');
	if (pos == string::npos) {
		l = "0";
	} else {
		l = l.substr(pos);
	}
}

string getBV(const string &s, int b) {
	if (s == "0")
		return "0";
	string ret;

	string tmp = s;
	while (tmp != "0") {
		long long remainder = 0;
		string quo;
		for (const auto &c : tmp) {
			int digit = c - '0';
			int cur = remainder * 10 + digit;
			quo.push_back(cur / b + '0');
			remainder = cur % b;
		}
		ret.push_back(remainder + '0');
		auto pos = quo.find_first_not_of('0');
		if (pos == string::npos) {
			tmp = "0";
		} else {
			tmp = quo.substr(pos);
		}
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

vector<long long> getFac(long long n, long long mod) {
	vector<long long> fac(1, 1);
	for (long long i = 1; i <= n; ++i) {
		fac.emplace_back((fac.back() * i) % mod);
	}
	return fac;
}

long long quickPow(long long x, long long n, long long mod) {
	if (n == 0)
		return 1;
	long long v = quickPow(x, n / 2, mod);
	long long vv = v * v % mod;
	return n & 1 ? vv * x % mod : vv;
}
long long comb(int m, int n, long long mod, const vector<long long> &fac) {
	if (n > m) return 0;
	long long a = fac[m];
	long long b = fac[n] * fac[m - n] % mod;
	long long rev_b = quickPow(b, mod - 2, mod);
	return a * rev_b % mod;
}

// 3 4 5 6
long long cnt(string &v, int low, int idx, int b, const vector<long long> &fac, bool tight, int mod) {
	if (idx == v.size() - 1) {
		return tight ? max(0, min((v[idx] - '0'), b) - low + 1) : b - low + 1;
	}

	long long ret = 0;
	if (tight) {
		int limit = min(v[idx] - '0', b);
		for (int i = low ; i <= limit ; ++i) {
			ret += cnt(v, i, idx + 1, b, fac, tight && i == limit, mod);
			ret %= mod;
		}
	} else {
		int digit = b - low + 1;
		int n = v.size() - idx;
		ret += comb(digit + n - 1, digit - 1, mod, fac);
		ret %= mod;
	}

	return ret;
}

int Solution::countNumbers(string l, string r, int b) {
	int mod = 1e9 + 7;
	string br = getBV(r, b);
	auto fac = getFac(br.size() + 10, mod);
	long long rv = cnt(br, 0, 0, b - 1, fac, true, mod);
	if (l == "0") return rv;

	minusOne(l);
	string bl = getBV(l, b);
	long long lv = cnt(bl, 0, 0, b - 1, fac, true, mod);
	long long ret = (rv - lv + mod) % mod;
	return ret;
}
