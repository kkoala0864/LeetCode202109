#include <Solution.h>

int Solution::numOfWays(int n) {
	unordered_map<int, long long> state, dp, next;
	long long mod = 1e9 + 7;
	int fullMask = (1 << 3) - 1;

	state[0] = 1;
	for (int i = 0 ; i < 3 ; ++i) {
		for (int k = 0 ; k < 3 ; ++k) {
			for (const auto& e : state) {
				int lm = e.first & fullMask;
				int mask = 1 << k;
				if (lm & mask) continue;
				mask |= (e.first << 3);
				next[mask] += e.second;
				next[mask] %= mod;
			}
		}
		state = move(next);
	}

	dp[0] = 1;
	for (int i = 0 ; i < n ; ++i) {
		for (const auto& d : dp) {
			for (const auto& e : state) {
				if (e.first & d.first) continue;
				next[e.first] += e.second;
				next[e.first] %= mod;
			}
		}
		dp = move(next);
	}
	int result = 0;
	for (const auto& e : dp) {
		result += e.second;
		result %= mod;
	}
	return result;
}
