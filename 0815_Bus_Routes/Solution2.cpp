#include <Solution.h>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <climits>

using std::queue;
using std::unordered_map;
using std::unordered_set;

int Solution::numBusesToDestination2(vector<vector<int>> &routes, int source, int target) {
	if (source == target)
		return 0;
	unordered_map<int, vector<int>> numToRoute;

	for (int ri = 0; ri < routes.size(); ++ri) {
		for (const auto &r : routes[ri]) {
			numToRoute[r].emplace_back(ri);
		}
	}

	unordered_set<int> targetRoutes;
	for (const auto &r : numToRoute[target])
		targetRoutes.emplace(r);

	queue<int> que;
	vector<int> routeShortestPath(routes.size(), INT_MAX);
	for (const auto &r : numToRoute[source]) {
		routeShortestPath[r] = 1;
		que.emplace(r);
	}

	while (!que.empty()) {
		int curRoute = que.front();
		que.pop();

		if (targetRoutes.count(curRoute))
			return routeShortestPath[curRoute];

		for (const auto &num : routes[curRoute]) {
			for (const auto &r : numToRoute[num]) {
				if (routeShortestPath[r] != INT_MAX)
					continue;
				routeShortestPath[r] = routeShortestPath[curRoute] + 1;
				que.emplace(r);
			}
		}
	}
	return -1;
}
