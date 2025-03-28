#include <Solution.h>
#include <iostream>
#include <climits>
#include <algorithm>

using std::min;

int dp(int node, int mask, const vector<vector<int>> &graph, vector<vector<int>> &cache, int endingMask) {
	if (cache[node][mask] != 0) {
		return cache[node][mask];
	}

	if ((mask & (mask - 1)) == 0) {
		return 0;
	}

	cache[node][mask] = INT_MAX - 1;

	for (const auto &iter : graph[node]) {
		if ((mask & (1 << iter)) != 0) {
			int alreadyVisited = dp(iter, mask, graph, cache, endingMask);
			int notVisited = dp(iter, mask ^ (1 << node), graph, cache, endingMask);
			int betterOption = min(alreadyVisited, notVisited);
			cache[node][mask] = min(cache[node][mask], 1 + betterOption);
		}
	}
	return cache[node][mask];
}

int Solution::shortestPathLength(vector<vector<int>> &graph) {
	int sz = graph.size();

	int endingMask = (1 << sz) - 1;
	vector<vector<int>> cache = vector<vector<int>>(sz + 1, vector<int>(endingMask + 1, 0));
	int result = INT_MAX;
	for (int i = 0; i < sz; ++i) {
		result = min(result, dp(i, endingMask, graph, cache, endingMask));
	}
	return result;
}
