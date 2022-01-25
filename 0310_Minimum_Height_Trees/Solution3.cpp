#include <Solution.h>
#include <iostream>
#include <queue>

using std::queue;

vector<int> Solution::findMinHeightTrees3(int n, vector<vector<int>>& edges) {
	if (n == 1) return vector<int>(1, 0);
	vector<vector<int>> outdegree(n, vector<int>());
	vector<int> cnt(n, 0);

	for (const auto& edge : edges) {
		outdegree[edge[0]].emplace_back(edge[1]);
		++cnt[edge[1]];
		outdegree[edge[1]].emplace_back(edge[0]);
		++cnt[edge[0]];
	}

	queue<int> que, next;
	vector<int> result;
	for (int i = 0 ; i < cnt.size() ; ++i) if (cnt[i] == 1) que.emplace(i);

	while (!que.empty()) {
		int node = que.front();
		que.pop();

		result.emplace_back(node);

		for (const auto& iter : outdegree[node]) {
			--cnt[iter];
			if (cnt[iter] == 1) next.emplace(iter);
		}

		if (que.empty()) {
			if (!next.empty()) result.clear();
			que = move(next);
		}
	}
	return result;
}
