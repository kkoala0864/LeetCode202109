#include <Solution.h>
#include <iostream>
#include <unordered_map>

// get prime factor
// if per prime factor cnt bigger than 1 is square number, exclude it
// get prime factor bitmask
// collect non square number to unordered_map<int, pair<int, int>> with bitmask and cnt
// calculate combination

using std::pair;

vector<int> getPS() {
	vector<int> prime(31, true);
	for (int i = 2; (i * i) <= 30; ++i) {
		if (!prime[i]) continue;
		for (int j = i; (i * j) <= 30; ++j) {
			prime[i * j] = false;
		}
	}
	vector<int> ps;
	for (int i = 2; i <= 30; ++i) {
		if (!prime[i]) continue;
		ps.emplace_back(i);
	}
	return ps;
}

bool getPrimeMask(int v, vector<int> &ps, int &mask) {

	for (const auto &p : ps) {
		if (v % p) continue;
		if (p * p > v) break;
		int cnt = 0;
		while (v % p == 0) {
			++cnt;
			v /= p;
		}
		if (cnt > 1) return false;
		mask = mask | (1 << p);
	}
	if (v > 1) {
		mask = mask | (1 << v);
	}
	return true;
}

long long quickPow(long long x, long long n, long long mod) {
	if (n == 0) return 1;
	long long v = quickPow(x, n / 2, mod);
	long long vv = v * v % mod;
	return n & 1 ? vv * x % mod : vv;
}

int Solution::squareFreeSubsets(vector<int> &nums) {
	unordered_map<int, pair<int, long long>> m;
	vector<int> ps = getPS();
	int cnt1 = 0;
	for (const auto &v : nums) {
		if (v == 1) {
			++cnt1;
			continue;
		}
		if (m.count(v)) {
			++m[v].second;
		} else {
			int mask = 0;
			if (getPrimeMask(v, ps, mask)) {
				m[v] = pair<int, long long>(mask, 1);
			}
		}
	}

	long long result = 0;
	long long mod = 1e9 + 7;

	vector<pair<int, long long>> list;
	list.emplace_back(pair<int, long long>(0, 1));
	for (const auto &e : m) {
		int curMask = e.second.first;
		int curCnt = e.second.second;
		int size = list.size();
		for (int i = 0; i < size; ++i) {
			if (curMask & list[i].first) continue;
			int mask = list[i].first | curMask;
			long long cnt = list[i].second * curCnt % mod;
			list.emplace_back(pair<int, long long>(mask, cnt));
			result += cnt;
			result %= mod;
		}
	}
	long long v1 = quickPow(2, cnt1, mod);
	return (result * v1 % mod + (v1 - 1)) % mod;
}
