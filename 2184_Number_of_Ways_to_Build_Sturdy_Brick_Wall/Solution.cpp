#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

void cnt(int width, vector<int>& bricks, unordered_map<int, int>& m) {
	vector<unordered_map<int, int>> dp(width + 1, unordered_map<int, int>());
	int mod = 1e9 + 7;

	dp[0][0] = 1;
	for (int i = 1 ; i <= width ; ++i) {
		for (const auto& b : bricks) {
			if (i < b) continue;
			for (const auto& e : dp[i-b]) {
				int mask = e.first | (1 << i);
				dp[i][mask] += e.second;
				dp[i][mask] %= mod;
			}
		}
	}

	m = dp.back();
}

int Solution::buildWall(int height, int width, vector<int>& bricks) {
	unordered_map<int, int> cur;

	int mod = 1e9 + 7;
	cnt(width, bricks, cur);
	unordered_map<int, unordered_set<int>> transition;
	for (const auto& e1 : cur) {
		for (const auto& e2 : cur) {
			int v = e1.first & e2.first;
			v &= ~1;
			v &= ~(1 << width);
			if (v == 0) transition[e1.first].emplace(e2.first);
		}
	}

	unordered_map<int, int> next;
	for (int i = 1 ; i < height ; ++i) {
		for (const auto& e1 : cur) {
			for (const auto& n : transition[e1.first]) {
				next[n] += e1.second;
				next[n] %= mod;
			}
		}
		cur = move(next);
	}

	int result = 0;
	for (const auto& e : cur) {
		result += e.second;
		result %= mod;
	}
	return result;
}
