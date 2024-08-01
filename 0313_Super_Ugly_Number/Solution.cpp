#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <queue>

using std::priority_queue;
using std::pair;

int Solution::nthSuperUglyNumber(int n, vector<int>& primes) {
	if (n == 1) return 1;

	vector<int> p(primes.size(), 0);
	priority_queue<pair<long, int>, vector<pair<long, int>>, std::greater<pair<long, int>>> pq;

	vector<long> dp = {1};

	for (int i = 0 ; i < primes.size() ; ++i) {
		pq.emplace(pair<long, int>(dp[p[i]] * (long)primes[i], i));
	}

	while (dp.size() < n) {
		long cur = pq.top().first;
		int idx = pq.top().second;
		pq.pop();
		if (cur > dp.back()) dp.emplace_back(cur);

		++p[idx];
		pq.emplace(pair<long, int>(dp[p[idx]] * (long)primes[idx], idx));
	}
	return dp.back();
}
