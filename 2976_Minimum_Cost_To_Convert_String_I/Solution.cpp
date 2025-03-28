#include <Solution.h>
#include <iostream>
#include <queue>

using std::pair;
using std::priority_queue;

void dijkstra(vector<vector<pair<int, int>>> &od, vector<int> &minCost, int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> pq;
	minCost[start] = 0;
	pq.emplace(pair<int, int>(0, start));

	while (!pq.empty()) {
		int cost = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		if (cost > minCost[node])
			continue;

		for (const auto &next : od[node]) {
			if (minCost[next.first] <= minCost[node] + next.second)
				continue;
			minCost[next.first] = minCost[node] + next.second;
			pq.emplace(pair<int, int>(minCost[next.first], next.first));
		}
	}
}

long long Solution::minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector<int> &cost) {
	vector<vector<pair<int, int>>> od(26, vector<pair<int, int>>());

	for (int i = 0; i < original.size(); ++i) {
		od[original[i] - 'a'].emplace_back(pair<int, int>(changed[i] - 'a', cost[i]));
	}
	vector<vector<int>> minCost(26, vector<int>(26, INT_MAX));

	long long result = 0;
	for (int i = 0; i < source.size(); ++i) {
		if (source[i] == target[i])
			continue;
		int si = source[i] - 'a';
		int ti = target[i] - 'a';
		if (minCost[si][si] == INT_MAX) {
			dijkstra(od, minCost[si], si);
		}
		if (minCost[si][ti] == INT_MAX)
			return -1;
		result += minCost[si][ti];
	}
	return result;
}
