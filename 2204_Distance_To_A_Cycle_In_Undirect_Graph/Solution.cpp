#include <Solution.h>
#include <iostream>
#include <queue>

using std::queue;

vector<int> Solution::distanceToCycle(int n, vector<vector<int>>& edges) {
	vector<int> result(n, 0);

	vector<vector<int>> od(n, vector<int>());
	vector<int> id(n, 0);

	for (const auto& e : edges) {
		od[e[0]].emplace_back(e[1]);
		od[e[1]].emplace_back(e[0]);
		++id[e[0]];
		++id[e[1]];
	}

	queue<int> que;
	for (int i = 0 ; i < n ; ++i) if (id[i] == 1) que.emplace(i);
	while (!que.empty()) {
		int cur = que.front();
		que.pop();
		result[cur] = INT_MAX;
		for (const auto& nv : od[cur]) {
			--id[nv];
			if (id[nv] == 1) que.emplace(nv);
		}
	}

	for (int i = 0 ; i < n ; ++i) {
		if (result[i] == 0) que.emplace(i);
	}
	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		for (const auto& nv : od[cur]) {
			if (result[nv] <= (result[cur] + 1)) continue;
			que.emplace(nv);
			result[nv] = result[cur] + 1;
		}
	}
	return result;
}
