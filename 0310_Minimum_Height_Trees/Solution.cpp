#include <Solution.h>
#include <iostream>
#include <queue>

using std::queue;

vector<int> Solution::findMinHeightTrees(int n, vector<vector<int>>& edges) {
	if (edges.empty()) return vector<int>(1, 0);
	vector<int> degree(n, 0);
	vector<vector<int>> relation(n, vector<int>());

	for (const auto& edge : edges) {
		relation[edge[0]].emplace_back(edge[1]);
		relation[edge[1]].emplace_back(edge[0]);
		++degree[edge[0]];
		++degree[edge[1]];
	}

	queue<int> que, next;
	vector<bool> visited(n, false);
	for(int i = 0 ; i < n ; ++i) if (degree[i] == 1) que.emplace(i);

	int totalSize = n - que.size();
	while (!que.empty() && totalSize > 0) {
		int node = que.front();
		que.pop();

		for (const auto& iter : relation[node]) {
			--degree[iter];
			if (degree[iter] == 1) next.emplace(iter);
		}

		if (que.empty()) {
			que = move(next);
			totalSize -= que.size();
		}
	}

	vector<int> result;
	while (!que.empty()) {
		result.emplace_back(que.front());
		que.pop();
	}
	return result;
}
