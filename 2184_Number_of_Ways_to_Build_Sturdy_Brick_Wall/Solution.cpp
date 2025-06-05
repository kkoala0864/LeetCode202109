#include <Solution.h>

int Solution::buildWall(int height, int width, vector<int>& bricks) {
	vector<unordered_map<int, long long>> state(width + 1, unordered_map<int, long long>());
	long long mod = 1e9 + 7;
	state[0][0] = 1;
	for (int i = 1 ; i <= width ; ++i) {
		for (const auto& b : bricks) {
			if (b > i) continue;
			for (const auto& e : state[i - b]) {
				state[i][e.first | (1 << (i-1))] += e.second;
				state[i][e.first | (1 << (i-1))] %= mod;
			}
		}
	}

	unordered_map<int, long long> dp, next;
	dp[0] = 1;
	for (int i = 1 ; i <= height ; ++i) {
		for (const auto& e : dp) {
			for (const auto& s : state[width]) {
				int mask = e.first & s.first;
				if (mask != (1 << (width - 1)) && mask != 0) continue;
				next[s.first] += (e.second * s.second);
				next[s.first] %= mod;
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
