#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <queue>

using std::priority_queue;
using std::max;
using std::pair;
using std::cout;
using std::endl;

void dijkstra(int n, int start, vector<vector<pair<int, int>>>& od, vector<vector<int>>& minCost) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> pq;

	pq.emplace(pair<int, int>(0, start));

	while (!pq.empty()) {
		int curCost = pq.top().first;
		int curNode = pq.top().second;
		pq.pop();

		if (curCost > minCost[start][curNode]) continue;

		for (const auto& next : od[curNode]) {
			if (minCost[start][next.first] < (curCost + next.second)) continue;
			minCost[start][next.first] = curCost + next.second;
			pq.emplace(pair<int, int>(minCost[start][next.first], next.first));
		}
	}
}

int Solution::findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
	vector<vector<int>> minCost(n, vector<int>(n, distanceThreshold + 1));
	vector<vector<pair<int, int>>> od(n, vector<pair<int, int>>());

	for (const auto& e : edges) {
		od[e[0]].emplace_back(pair<int, int>(e[1], e[2]));
		od[e[1]].emplace_back(pair<int, int>(e[0], e[2]));
	}

	for (int i = 0 ; i < n ; ++i) {
		minCost[i][i] = 0;
		dijkstra(n, i, od, minCost);
	}

	int minReach = n;
	int result = -1;
	for (int i = 0 ; i < n ; ++i) {
		int cnt = 0;
		for (int j = 0 ; j < n ; ++j) {
			if (i == j || minCost[i][j] == (distanceThreshold + 1)) continue;
			++cnt;
		}
		if (minReach > cnt) {
			minReach = cnt;
			result = i;
		} else if (minReach == cnt) {
			result = max(result, i);
		}
	}
	return result;
}
