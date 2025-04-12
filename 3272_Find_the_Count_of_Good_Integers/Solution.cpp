#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <vector>

long long quickPow(long long x, long long n) {
	if (n == 0) return 1;
	long long v = quickPow(x, n >> 1);
	long long vv = v * v;
	return n & 1 ? vv * x : vv;
}

vector<long long> getFac() {
	vector<long long> fac(1, 1);
	for (long long i = 1 ; i <= 10 ; ++i) fac.emplace_back(fac.back() * i);
	return fac;
}

// 1 2 3 4 5 -> 3  [100, 1000)
// 1 2 3 4 -> 2 -> [10, 100)
long long Solution::countGoodIntegers(int n, int k) {
	long long strLen = (n >> 1) + (n & 1);

	unordered_set<string> us;
	int skip = n & 1;
	for (long long i = quickPow(10, strLen - 1) ; i < quickPow(10, strLen) ; ++i) {
		string s = to_string(i);
		s += string(s.rbegin() + skip, s.rend());
		long long v = stoll(s);
		if (v % k) continue;

		sort(s.begin(), s.end());
		us.emplace(s);
	}

	long long result = 0;
	auto fac = getFac();
	for (const auto& s : us) {
		vector<int> cnt(10, 0);
		for (const auto& c : s) {
			++cnt[c-'0'];
		}

		long long cur = (n - cnt[0]) * fac[n-1];
		for (const auto& v : cnt) cur /= fac[v];
		result += cur;
	}
	return result;
}
