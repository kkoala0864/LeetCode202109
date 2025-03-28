#include <Solution.h>
#include <iostream>
#include <unordered_set>
#include <unordered_map>

using std::unordered_map;
using std::unordered_set;

bool Solution::canCross(vector<int> &stones) {
	int s = stones.size();

	unordered_map<int, unordered_set<int>> dp;
	dp[0].emplace(0);

	for (int i = 0; i < s; ++i) {
		if (dp.count(stones[i]) == 0)
			continue;

		for (const auto &u : dp[stones[i]]) {
			if (u - 1 >= 0) {
				dp[stones[i] + u - 1].emplace(u - 1);
			}
			dp[stones[i] + u].emplace(u);
			dp[stones[i] + u + 1].emplace(u + 1);
		}
	}
	return dp[stones.back()].size() > 0;
}
