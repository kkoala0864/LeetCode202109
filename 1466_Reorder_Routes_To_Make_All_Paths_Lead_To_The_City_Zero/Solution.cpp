#include <Solution.h>
#include <iostream>
#include <queue>

using std::queue;

int Solution::minReorder(int n, vector<vector<int>> &connections) {
	vector<vector<int>> indegree(n, vector<int>());
	vector<vector<int>> outdegree(n, vector<int>());
	vector<bool> visited(n, false);

	for (const auto &c : connections) {
		indegree[c[1]].emplace_back(c[0]);
		outdegree[c[0]].emplace_back(c[1]);
	}

	visited[0] = true;
	queue<int> que;
	que.emplace(0);
	int result = 0;

	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		for (const auto &e : indegree[cur]) {
			if (visited[e])
				continue;
			visited[e] = true;
			que.emplace(e);
		}

		for (const auto &e : outdegree[cur]) {
			if (visited[e])
				continue;
			visited[e] = true;
			++result;
			que.emplace(e);
		}
	}
	return result;
}
