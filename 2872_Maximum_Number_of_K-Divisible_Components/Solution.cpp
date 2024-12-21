#include <Solution.h>
#include <iostream>
#include <queue>

using std::queue;
using std::cout;
using std::endl;

int Solution::maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
	vector<vector<int>> od(n, vector<int>());
	vector<int> id(n, 0);

	for (const auto& e : edges) {
		++id[e[0]];
		++id[e[1]];
		od[e[0]].emplace_back(e[1]);
		od[e[1]].emplace_back(e[0]);
	}
	vector<bool> visited(n, false);
	int result = 0;

	queue<int> que, next;
	for (int i = 0 ; i < n ; ++i) {
		if (id[i] > 1) continue;
		que.emplace(i);
		visited[i] = true;
	}

	while (!que.empty()) {
		int cur = que.front();
		que.pop();
		if (values[cur] % k == 0) {
			++result;
		}
		for (const auto& nv : od[cur]) {
			--id[nv];
			values[nv] += values[cur];
			values[nv] %= k;
			if (id[nv] < 2 && !visited[nv]) {
				visited[nv] = true;
				next.emplace(nv);
			}
		}
		if (que.empty()) {
			que = move(next);
		}
	}
	return result;
}
