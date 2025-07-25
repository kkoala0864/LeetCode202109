#include <Solution.h>

long long getCnt(long long v, long long mod) {
	long long result = (v * (v - 1) / 2) % mod;
	return result;
}

int Solution::countTrapezoids(vector<vector<int>>& points) {
	unordered_map<int, long long> yCnt;
	long long maxCnt = 0;
	for (const auto& p : points) {
		++yCnt[p[1]];
		maxCnt = max(maxCnt, yCnt[p[1]]);
	}

	long long result = 0;
	long long mod = 1e9 + 7;
	vector<long long> cnts;
	vector<long long> preSum(1, 0);
	for (const auto& e : yCnt) {
		if (e.second == 1) continue;
		long long v = getCnt(e.second, mod);
		cnts.emplace_back(v);
		preSum.emplace_back((preSum.back() + v) % mod);
	}
	for (int i = 1 ; i < cnts.size() ; ++i) {
		result += (cnts[i] * preSum[i] % mod);
		result %= mod;
	}

	return result;
}
