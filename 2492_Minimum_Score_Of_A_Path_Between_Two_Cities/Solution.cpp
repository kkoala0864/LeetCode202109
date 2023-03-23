#include <Solution.h>
#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>

using std::queue;
using std::pair;
using std::min;

int Solution::minScore(int n, vector<vector<int>>& roads) {
	vector<int> minCost(n, INT_MAX);
	vector<vector<pair<int, int>>> cost(n);

	for (const auto& r : roads) {
		cost[r[0] - 1].emplace_back(pair<int, int>(r[1]-1, r[2]));
		cost[r[1] - 1].emplace_back(pair<int, int>(r[0]-1, r[2]));
	}

	queue<int> que;
	que.emplace(0);

	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		for (const auto& c : cost[cur]) {
			if (minCost[c.first] <= min(minCost[cur], c.second)) continue;
			minCost[c.first] = min(minCost[cur], c.second);
			que.emplace(c.first);
		}
	}
	return minCost.back();
}
