#include <Solution.h>
#include <iostream>
#include <queue>
#include <algorithm>

using std::queue;
using std::sort;

vector<int> Solution::eventualSafeNodes2(vector<vector<int>> &graph) {
	int n = graph.size();
	queue<int> que;
	vector<int> cnt(n, 0);
	vector<vector<int>> indegree(n, vector<int>());

	for (int i = 0; i < graph.size(); ++i) {
		if (graph[i].empty())
			que.emplace(i);
		else {
			cnt[i] = graph[i].size();
			for (const auto &node : graph[i]) {
				indegree[node].emplace_back(i);
			}
		}
	}

	vector<int> result;
	while (!que.empty()) {
		int cur = que.front();
		que.pop();
		result.emplace_back(cur);

		for (const auto &node : indegree[cur]) {
			--cnt[node];
			if (cnt[node] == 0)
				que.emplace(node);
		}
	}
	sort(result.begin(), result.end());
	return result;
}
