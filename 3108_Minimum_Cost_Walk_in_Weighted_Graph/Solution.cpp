#include <Solution.h>
#include <iostream>

int find(vector<int>& root, int idx) {
	if (root[idx] == idx) return idx;
	return root[idx] = find(root, root[idx]);
}

vector<int> Solution::minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
	vector<int> cost(n, INT_MAX);
	vector<int> root;
	for (int i = 0 ; i < n ; ++i) root.emplace_back(i);

	for (const auto& v : edges) {
		int lr = find(root, v[0]);
		int rr = find(root, v[1]);
		int idx = min(lr, rr);
		if (lr != rr) {
			cost[idx] = cost[lr] & cost[rr];
			root[lr] = root[rr] = idx;
		}
		cost[idx] = cost[idx] == INT_MAX ? v[2] : cost[idx] & v[2];
	}

	vector<int> result;
	for (const auto& q : query) {
		int v1 = find(root, q[0]);
		int v2 = find(root, q[1]);
		result.emplace_back(v1 == v2 ? cost[v1] : -1);
	}
	return result;
}
