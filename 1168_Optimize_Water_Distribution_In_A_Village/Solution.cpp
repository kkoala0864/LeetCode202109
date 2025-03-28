#include <Solution.h>
#include <iostream>
#include <queue>
#include <algorithm>
#include <unordered_set>

using std::cout;
using std::endl;
using std::min;
using std::priority_queue;
using std::unordered_set;

int find(vector<int> &root, int idx) {
	if (root[idx] == idx)
		return idx;
	return root[idx] = find(root, root[idx]);
}

int Solution::minCostToSupplyWater(int n, vector<int> &wells, vector<vector<int>> &pipes) {
	priority_queue<vector<int>, vector<vector<int>>, std::greater<vector<int>>> pq;
	for (const auto &p : pipes) {
		pq.emplace(vector<int>({p[2], p[0] - 1, p[1] - 1}));
	}

	vector<int> root;
	for (int i = 0; i < n; ++i)
		root.emplace_back(i);
	vector<int> cost = wells;

	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		int lr = find(root, cur[1]);
		int rr = find(root, cur[2]);
		if (lr == rr)
			continue;

		int mv = cost[lr] + cost[rr];
		int bcw = wells[lr] > wells[rr] ? lr : rr;
		int lcw = wells[lr] < wells[rr] ? lr : rr;
		if (cur[0] > wells[bcw])
			continue;
		root[lr] = root[rr] = lcw;
		cost[lr] = cost[rr] = cost[lr] + cost[rr] + cur[0] - wells[bcw];
	}

	unordered_set<int> us;
	for (int i = 0; i < n; ++i)
		us.emplace(find(root, i));
	int result = 0;
	for (const auto &e : us)
		result += cost[e];
	return result;
}
