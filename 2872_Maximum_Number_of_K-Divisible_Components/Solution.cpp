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

	vector<int> list, next;
	for (int i = 0 ; i < n ; ++i) {
		if (id[i] > 1) continue;
		list.emplace_back(i);
		visited[i] = true;
	}

	while (!list.empty()) {
		for (const auto& v : list) {
			if (values[v] % k == 0) {
				++result;
			}
			for (const auto& nv : od[v]) {
				--id[nv];
				values[nv] += values[v];
				values[nv] %= k;
				if (id[nv] < 2 && !visited[nv]) {
					visited[nv] = true;
					next.emplace_back(nv);
				}
			}
		}
		list = move(next);
	}
	return result;
}
