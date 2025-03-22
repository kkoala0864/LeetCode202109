#include <Solution.h>
#include <iostream>
#include <queue>
#include <algorithm>

using std::priority_queue;
using std::pair;
using std::min;

int Solution::minimumDistance(int n, vector<vector<int>>& edges, int s, vector<int>& marked) {
	vector<int> minCost(n, INT_MAX);
	vector<vector<pair<int, int>>> neighbor(n, vector<pair<int, int>>());

	for (const auto& e : edges) {
		neighbor[e[0]].emplace_back(pair<int, int>(e[1], e[2]));
	}

	priority_queue<int> pq;
	minCost[s] = 0;
	pq.emplace(s);

	while (!pq.empty()) {
		int cur = pq.top();
		pq.pop();

		for (const auto& n : neighbor[cur]) {
			if (minCost[n.first] > minCost[cur] + n.second) {
				minCost[n.first] = minCost[cur] + n.second;
				pq.emplace(n.first);
			}
		}
	}
	int result = INT_MAX;
	for (const auto& v : marked) {
		result = min(result, minCost[v]);
	}
	return result == INT_MAX ? -1 : result;
}
