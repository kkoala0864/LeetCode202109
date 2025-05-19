#include <Solution.h>

int Solution::colorTheGrid(int m, int n) {
	long long mod = 1e9 + 7;

	unordered_map<int, long long> dp, next;

	unordered_set<int> state, nextState;

	for (int i = 0 ; i < 3 ; ++i) state.emplace(1 << i);
	for (int i = 1 ; i < m ; ++i) {
		for (int j = 0 ; j < 3 ; ++j) {
			for (const auto& s : state) {
				int lastState = s >> (3 * (i-1));
				if ((1 << j) & lastState) continue;
				nextState.emplace(s | (1 << ((3 * i) + j)));
			}
		}
		state = move(nextState);
	}

	dp[0] = 1;
	for (int i = 0 ; i < n ; ++i) {
		for (const auto& e : dp) {
			for (const auto& s : state) {
				if (e.first & s) continue;
				next[s] += e.second;
				next[s] %= mod;
			}
		}
		dp = move(next);
	}
	long long result = 0;
	for (const auto& e : dp) {
		result = (result + e.second) % mod;
	}
	return result;
}
