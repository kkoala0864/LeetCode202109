#include <Solution.h>
#include <iostream>
#include <set>
#include <stack>
#include <algorithm>
#include <unordered_map>

void getPrimeArray(vector<int> &ps) {
	vector<int> prime(1e5 + 1, true);
	for (int i = 2; (i * i) <= 1e5; ++i) {
		if (!prime[i])
			continue;
		for (int j = i; (i * j) <= 1e5; ++j) {
			prime[i * j] = false;
		}
	}
	for (int i = 2; i <= 1e5; ++i) {
		if (!prime[i])
			continue;
		ps.emplace_back(i);
	}
}

vector<int> getPrimeScore(vector<int> &nums, const vector<int> &primes) {
	vector<int> result(nums.size(), 0);
	for (int i = 0; i < nums.size(); ++i) {
		int cnt = 0, cur = nums[i];
		for (const auto &p : primes) {
			if (p * p > cur)
				break;
			if (cur % p == 0)
				++result[i];
			while (cur % p == 0)
				cur /= p;
		}
		if (cur > 1)
			++result[i];
	}
	return result;
}

long long quickPow(long long x, long long n, long long mod) {
	if (n == 0)
		return 1;
	long long v = quickPow(x, n / 2, mod);
	long long vv = v * v % mod;
	return n & 1 ? x * vv % mod : vv;
}

int Solution::maximumScore(vector<int> &nums, int k) {
	vector<int> ps;
	getPrimeArray(ps);
	auto scores = getPrimeScore(nums, ps);

	int size = nums.size();
	vector<int> lastBig(size, -1);
	vector<int> nextBig(size, size);
	stack<int> st;
	for (int i = 0; i < nums.size(); ++i) {
		while (!st.empty() && scores[st.top()] < scores[i]) {
			nextBig[st.top()] = i;
			st.pop();
		}
		if (!st.empty()) {
			lastBig[i] = st.top();
		}
		st.emplace(i);
	}

	unordered_map<int, long long> scoreMap;

	for (int i = 0; i < size; ++i) {
		scoreMap[nums[i]] += (long long)(i - lastBig[i]) * (long long)(nextBig[i] - i);
	}

	vector<pair<int, long long>> sortedScores(scoreMap.begin(), scoreMap.end());
	sort(sortedScores.rbegin(), sortedScores.rend());

	long long result = 1;
	long long mod = 1e9 + 7;

	for (auto &e : sortedScores) {
		if (k == 0)
			break;
		long long v = min((long long)k, e.second);
		k -= v;
		result *= (quickPow(e.first, v, mod) % mod);
		result %= mod;
	}
	return result;
}
