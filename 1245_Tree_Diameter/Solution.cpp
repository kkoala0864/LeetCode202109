#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>

using std::cout;
using std::endl;
using std::max;
using std::queue;
using std::unordered_map;
using std::unordered_set;

int Solution::treeDiameter(vector<vector<int>> &edges) {
	unordered_map<int, vector<int>> graph;
	unordered_map<int, int> icnt;
	for (const auto &e : edges) {
		graph[e[0]].emplace_back(e[1]);
		graph[e[1]].emplace_back(e[0]);
		++icnt[e[0]];
		++icnt[e[1]];
	}

	queue<int> que, next;
	unordered_set<int> visited;
	int result = 0;
	for (const auto &g : graph) {
		if (g.second.size() > 1)
			continue;
		que.emplace(g.first);
		visited.emplace(g.first);
	}

	int size = 0;

	while (!que.empty()) {
		int cur = que.front();
		que.pop();
		++size;
		for (const auto &n : graph[cur]) {
			if (visited.count(n))
				continue;
			--icnt[n];
			if (icnt[n] == 1 || icnt[n] == 0) {
				visited.emplace(n);
				next.emplace(n);
			}
		}
		if (que.empty()) {
			++result;
			que = move(next);
			if (que.empty()) {
				return 2 * (result - 1) + (size == 2 ? 1 : 0);
			}
			size = 0;
		}
	}
	return 0;
}
