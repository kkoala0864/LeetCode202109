#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>

using std::max;
using std::min;
using std::queue;
using std::unordered_map;

int bfs(vector<vector<int>> &od, int start, int &root) {
	int size = od.size();
	vector<int> visited(size, -1);
	visited[start] = 0;
	int level = 0;

	queue<int> que, next;
	que.emplace(start);

	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		root = min(root, cur);
		for (const auto &nv : od[cur]) {
			if (visited[nv] == -1) {
				visited[nv] = visited[cur] + 1;
				next.emplace(nv);
			} else {
				if (visited[nv] == visited[cur]) {
					return -1;
				}
			}
		}
		if (que.empty()) {
			que = move(next);
			++level;
		}
	}
	return level;
}

int Solution::magnificentSets(int n, vector<vector<int>> &edges) {
	vector<vector<int>> od(n, vector<int>());
	for (const auto &e : edges) {
		od[e[0] - 1].emplace_back(e[1] - 1);
		od[e[1] - 1].emplace_back(e[0] - 1);
	}
	unordered_map<int, int> m;
	for (int i = 0; i < n; ++i) {
		int root = i;
		int maxlen = bfs(od, i, root);
		if (maxlen == -1)
			return -1;
		m[root] = max(m[root], maxlen);
	}
	int sum = 0;
	for (const auto &e : m) {
		sum += e.second;
	}
	return sum;
}
