#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::min;

void tarjan(int& t, int curNode, int parent, vector<vector<int>>& adj, vector<int>& firstT, vector<int>& minT, vector<vector<int>>& result) {
	firstT[curNode] = minT[curNode] = ++t;

	for (auto& child : adj[curNode]) {
		if (child == parent) continue;
		if (firstT[child] == INT_MAX) tarjan(t, child, curNode, adj, firstT, minT, result);

		minT[curNode] = min(minT[child], minT[curNode]);

		if (firstT[curNode] < minT[child]) {
			result.push_back({curNode, child});
		}
	}
}

vector<vector<int>> Solution::criticalConnections2(int n, vector<vector<int>>& connections) {
	vector<vector<int>> adj(n, vector<int>());
	for (const auto& connection : connections) {
		adj[connection[0]].emplace_back(connection[1]);
		adj[connection[1]].emplace_back(connection[0]);
	}

	vector<int> minT(n, INT_MAX);
	vector<int> firstT(n, INT_MAX);
	vector<vector<int>> result;
	int t = 0;
	tarjan(t, 0, -1, adj, firstT, minT, result);
	return result;
}

