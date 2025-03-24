#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <queue>

using std::min;
using std::pair;
using std::priority_queue;

vector<long long> Dijkstra(int n, vector<vector<pair<int, long long>>>& ad, int src) {
	vector<long long> minCost(n, LLONG_MAX);
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, std::greater<>> pq;
	minCost[src] = 0;
	pq.emplace(pair<long long, int>(0, src));

	while (!pq.empty()) {
		long long cost = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		if (cost > minCost[node]) continue;
		for (const auto& n : ad[node]) {
			if (minCost[n.first] > (cost + n.second)) {
				minCost[n.first] = cost + n.second;
				pq.emplace(pair<long long, int>(minCost[n.first], n.first));
			}
		}
	}
	return minCost;
}

long long Solution::minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
	vector<vector<pair<int, long long>>> ad(n, vector<pair<int, long long>>());
	vector<vector<pair<int, long long>>> revAd(n, vector<pair<int, long long>>());

	for (const auto& e : edges) {
		ad[e[0]].emplace_back(pair<int, long long>(e[1], e[2]));
		revAd[e[1]].emplace_back(pair<int, long long>(e[0], e[2]));
	}

	auto minCost1 = Dijkstra(n, ad, src1);
	auto minCost2 = Dijkstra(n, ad, src2);
	auto minCostDest = Dijkstra(n, revAd, dest);

	long long result = LLONG_MAX;
	for (int i = 0 ; i < n ; ++i) {
		if (minCost1[i] == LLONG_MAX || minCost2[i] == LLONG_MAX || minCostDest[i] == LLONG_MAX) continue;
		result = min(result, minCost1[i] + minCost2[i] + minCostDest[i]);
	}
	return result == LLONG_MAX ? -1 : result;

}
