#include <Solution.h>

vector<long long> getPL(long long maxV) {
	vector<bool> isPrime(maxV + 1, false);

	for (int i = 2 ; (i * i) <= maxV ; ++i) {
		if (isPrime[i]) continue;
		for (int j = i ; (i * j) <= maxV ; ++j) {
			isPrime[i * j] = true;
		}
	}

	vector<long long> pl;
	for (int i = 2 ; i <= maxV ; ++i) {
		if (isPrime[i]) continue;
		pl.emplace_back(i);
	}
	return pl;
}

bool isPrime(long long v, vector<long long>& pl) {
	for (const auto& p : pl) {
		if (v == p) return true;
		if (v < p || v % p == 0) return false;
	}
	return true;
}

long long Solution::sumOfLargestPrimes(string s) {
	long long maxValue = stoll(s);
	long long sqrtMax = sqrt(maxValue) + 1;

	auto pl = getPL(sqrtMax + 1);
	set<long long> st;

	for (int sz = 1 ; sz <= s.size() ; ++sz) {
		for (int l = 0 ; (l + sz) <= s.size() ; ++l) {
			long long v = stoll(s.substr(l, sz));
			st.emplace(v);
		}
	}
	int cnt = 0;
	long long result = 0;
	auto iter = st.rbegin();
	for (auto iter = st.rbegin() ; iter != st.rend() ; ++iter) {
		if (isPrime(*iter, pl)) {
			result += *iter;
			++cnt;
		}
		if (cnt == 3) break;
	}
	return result;
}

