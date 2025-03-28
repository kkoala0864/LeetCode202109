#include <Solution.h>
#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>

using std::min;
using std::pair;
using std::queue;

int Solution::findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k) {
	vector<vector<int>> dp(n, vector<int>(k + 2, INT_MAX));
	dp[src][0] = 0;

	vector<vector<pair<int, int>>> srcToDstCost(n, vector<pair<int, int>>());

	for (const auto &f : flights) {
		srcToDstCost[f[0]].emplace_back(pair<int, int>(f[1], f[2]));
	}

	for (int i = 1; i < k + 2; ++i) {
		for (int fi = 0; fi < n; ++fi) {
			if (dp[fi][i - 1] != INT_MAX) {
				for (const auto &f : srcToDstCost[fi]) {
					dp[f.first][i] = min(dp[fi][i - 1] + f.second, dp[f.first][i]);
				}
			}
		}
	}
	int result = INT_MAX;
	for (const auto &cost : dp[dst]) {
		result = min(result, cost);
	}
	return result == INT_MAX ? -1 : result;
}
