#include <Solution.h>
#include <iostream>
#include <queue>
#include <algorithm>

using std::sort;
using std::queue;

vector<int> Solution::eventualSafeNodes(vector<vector<int>>& graph) {
	queue<int> que;

	vector<int> result;
	vector<vector<int>> edge(graph.size(), vector<int>());
	vector<int> cnt(graph.size(), 0);

	for (int i = 0 ; i < graph.size() ; ++i) {
		if (graph[i].empty()) que.emplace(i);
		else {
			cnt[i] = graph[i].size();
			for(const auto& e : graph[i]) edge[e].emplace_back(i);
		}
	}

	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		result.emplace_back(cur);
		for (const auto& adj : edge[cur]) {
			--cnt[adj];
			if (cnt[adj] == 0) que.emplace(adj);
		}
	}
	sort(result.begin(), result.end());
	return result;

}
