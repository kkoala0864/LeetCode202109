#include <Solution.h>

vector<int> Solution::mostSimilar(int n, vector<vector<int>>& roads, vector<string>& names, vector<string>& targetPath) {
	vector<vector<int>> adj(n, vector<int>());
	for (const auto& r : roads) {
		adj[r[0]].emplace_back(r[1]);
		adj[r[1]].emplace_back(r[0]);
	}

	vector<pair<int, vector<int>>> dp(n, pair<int, vector<int>>(INT_MAX / 2, vector<int>()));
	for (int i = 0 ; i < n ; ++i) {
		dp[i].first = names[i] != targetPath[0];
		dp[i].second.emplace_back(i);
	}
	for (int i = 1 ; i < targetPath.size() ; ++i) {
		vector<pair<int, vector<int>>> next(n, pair<int, vector<int>>(INT_MAX / 2, vector<int>()));
		for (int li = 0 ; li < n ; ++li) {
			for (const auto& ci : adj[li]) {
				int diff = names[ci] != targetPath[i];
				int cost = dp[li].first + diff;
				if (next[ci].first > cost) {
					next[ci].first = cost;
					next[ci].second = dp[li].second;
					next[ci].second.emplace_back(ci);
				}
			}
		}
		dp = std::move(next);
	}
	vector<int> result;
	int minCost = INT_MAX;
	for (int i = 0 ; i < n ; ++i) {
		if (dp[i].first < minCost) {
			minCost = dp[i].first;
			result = dp[i].second;
		}
	}
	return result;
}
