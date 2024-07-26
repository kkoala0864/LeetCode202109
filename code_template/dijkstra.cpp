#include <Solution.h>
#include <iostream>
#include <queue>
#include <climits>

using std::priority_queue;
using std::pair;

vector<int> Solution::dijstra(vector<vector<int>>& edges, int n, int start) {
	vector<vector<pair<int, int>>> od(n, vector<pair<int, int>>());

	vector<int> minCost(n, INT_MAX);
	minCost[start] = 0;

	for (const auto& e : edges) {
		od[e[0]].emplace_back(pair<int, int>(e[1], e[2]));
		od[e[1]].emplace_back(pair<int, int>(e[0], e[2]));
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> pq;

	pq.emplace(pair<int, int>(0, start));

	while (!pq.empty()) {
		int curCost = pq.top().first;
		int curNode = pq.top().second;
		pq.pop();

		if (curCost > minCost[curNode]) continue;

		for (const auto& next : od[curNode]) {
			if (minCost[next.first] <= (curCost + next.second)) continue;
			minCost[next.first] = curCost + next.second;
			pq.emplace(pair<int, int>(minCost[next.first], next.first));
		}
	}
	return minCost;
}
