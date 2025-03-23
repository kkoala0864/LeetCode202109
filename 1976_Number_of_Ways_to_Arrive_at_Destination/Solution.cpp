#include <Solution.h>
#include <iostream>
#include <queue>

using std::priority_queue;
using std::pair;
using std::cout;
using std::endl;

int Solution::countPaths(int n, vector<vector<int>>& roads) {
	vector<long long> minCost(n, LLONG_MAX);
	vector<int> way(n, 0);
	int mod = 1e9 + 7;

	vector<vector<pair<int, int>>> ad(n, vector<pair<int, int>>());

	for (const auto r : roads) {
		ad[r[0]].emplace_back(pair<long long, int>(r[1], r[2]));
		ad[r[1]].emplace_back(pair<long long, int>(r[0], r[2]));
	}
	way[0] = 1;
	minCost[0] = 0;
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, std::greater<>> pq;
	pq.emplace(pair<int, int>(0, 0));

	while (!pq.empty()) {
		long long curCost = pq.top().first;
		int curNode = pq.top().second;
		pq.pop();

		if (curCost > minCost[curNode]) continue;

		for (const auto& a : ad[curNode]) {
			long long nextCost = curCost + a.second;
			if (nextCost > minCost[a.first]) continue;
			if (nextCost < minCost[a.first]) {
				way[a.first] = way[curNode] % mod;
				minCost[a.first] = nextCost;
				pq.emplace(pair<long long, int>(minCost[a.first], a.first));
			} else if (nextCost == minCost[a.first]) {
				way[a.first] = (way[a.first] + way[curNode]) % mod;
			}
		}
	}
	return way.back() % mod;
}
