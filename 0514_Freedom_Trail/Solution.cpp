#include <Solution.h>
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::min;
using std::pair;
using std::vector;

int Solution::findRotateSteps(string ring, string key) {
	vector<vector<int>> idx(26, vector<int>());
	for (int i = 0; i < ring.size(); ++i) {
		idx[ring[i] - 'a'].emplace_back(i);
	}

	int rs = ring.size();
	vector<vector<pair<int, int>>> dp(key.size() + 1, vector<pair<int, int>>());
	dp[0].emplace_back(pair<int, int>(0, 0));

	for (int i = 0; i < key.size(); ++i) {
		int targetIdx = key[i] - 'a';

		for (const auto &n : idx[targetIdx]) {
			int minCost = INT_MAX;
			for (const auto &last : dp[i]) {
				int lidx = last.first;
				int lcost = last.second;
				int v = min(abs(lidx - n), rs - abs(lidx - n));
				minCost = min(minCost, lcost + v + 1);
			}
			dp[i + 1].emplace_back(pair<int, int>(n, minCost));
		}
	}

	int result = INT_MAX;
	for (const auto &e : dp.back()) {
		result = min(result, e.second);
	}
	return result;
}
