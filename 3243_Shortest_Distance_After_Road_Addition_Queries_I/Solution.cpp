#include <Solution.h>
#include <iostream>
#include <queue>

using std::queue;
using std::cout;
using std::endl;

int bfs(vector<vector<int>>& od, int n) {
	queue<int> que, next;
	int result = 0;

	que.emplace(0);
	vector<bool> visited(n, false);
	visited[0] = true;

	while (!que.empty()) {
		int cur = que.front();
		que.pop();
		if (cur == n-1) return result;

		for (const auto& n : od[cur]) {
			if (visited[n]) continue;
			next.emplace(n);
			visited[n] = true;
		}

		if (que.empty()) {
			que = move(next);
			++result;
		}
	}
	return -1;
}

vector<int> Solution::shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
	vector<vector<int>> od(n, vector<int>());

	for (int i = 0 ; i < n - 1 ; ++i) {
		od[i].emplace_back(i+1);
	}

	vector<int> result;
	for (const auto& q : queries) {
		od[q[0]].emplace_back(q[1]);
		result.push_back(bfs(od, n));
	}
	return result;
}
