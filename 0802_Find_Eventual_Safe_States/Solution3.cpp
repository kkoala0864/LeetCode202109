#include <Solution.h>
#include <iostream>
#include <queue>
#include <algorithm>

using std::queue;
using std::sort;

vector<int> Solution::eventualSafeNodes3(vector<vector<int>>& graph) {
	vector<int> oc;
	queue<int> que;

	vector<vector<int>> from(graph.size(), vector<int>());
	for (int i = 0 ; i < graph.size() ; ++i) {
		for (const auto& f : graph[i]) {
			from[f].emplace_back(i);
		}
		oc.emplace_back(graph[i].size());
		if (graph[i].empty()) {
			que.emplace(i);
		}
	}

	vector<int> result;
	while (!que.empty()) {
		int cur = que.front();
		que.pop();
		result.emplace_back(cur);
		for (const auto& f : from[cur]) {
			--oc[f];
			if (oc[f] == 0) que.emplace(f);
		}
	}
	sort(result.begin(), result.end());
	return result;
}
