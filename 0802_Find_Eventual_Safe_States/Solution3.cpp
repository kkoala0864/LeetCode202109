#include <Solution.h>
#include <iostream>
#include <queue>
#include <algorithm>

using std::sort;
using std::queue;

vector<int> Solution::eventualSafeNodes3(vector<vector<int>>& graph) {
	vector<int> result;
	queue<int> que;
	vector<int> cnt(graph.size(), 0);
	vector<vector<int>> indegree(graph.size(), vector<int>());
	for (int i = 0 ; i < graph.size() ; ++i) {
		if (graph[i].empty()) que.emplace(i);
		else {
			cnt[i] = graph[i].size();
			for (const auto& e : graph[i]) {
				indegree[e].emplace_back(i);
			}
		}
	}

	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		result.emplace_back(cur);
		for (const auto& e : indegree[cur]) {
			--cnt[e];
			if (cnt[e] == 0) que.emplace(e);
		}
	}
	sort(result.begin(), result.end());
	return result;
}
