#include <Solution.h>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using std::cout;
using std::endl;
using std::queue;
using std::unordered_map;
using std::unordered_set;

int Solution::numBusesToDestination(vector<vector<int>> &routes, int source, int target) {
	if (source == target)
		return 0;
	unordered_map<int, unordered_set<int>> uMap;
	vector<unordered_set<int>> rMap(routes.size(), unordered_set<int>());
	for (int i = 0; i < routes.size(); ++i) {
		for (int j = 0; j < routes[i].size(); ++j) {
			uMap[routes[i][j]].emplace(i);
		}
	}

	unordered_set<int> sr = uMap[source];
	unordered_set<int> tr = uMap[target];
	for (int i = 0; i < routes.size(); ++i) {
		for (int j = 0; j < routes[i].size(); ++j) {
			if (uMap.find(routes[i][j]) == uMap.end())
				continue;
			for (const auto &r : uMap[routes[i][j]]) {
				if (r != i) {
					rMap[i].emplace(r);
					rMap[r].emplace(i);
				}
			}
			uMap.erase(routes[i][j]);
		}
	}

	vector<int> minStep(routes.size(), -1);
	queue<int> que;
	for (const auto &srv : sr) {
		que.emplace(srv);
		minStep[srv] = 1;
	}

	while (!que.empty()) {
		int cur = que.front();
		que.pop();
		if (tr.find(cur) != tr.end())
			return minStep[cur];

		for (const auto &n : rMap[cur]) {
			if (minStep[n] >= 0)
				continue;
			que.emplace(n);
			minStep[n] = minStep[cur] + 1;
		}
	}
	return -1;
}
