#include <Solution.h>
#include <iostream>
#include <queue>

int Solution::minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
	vector<int> idc(n, 0);
	vector<vector<int>> od(n, vector<int>());

	for (const auto& r : relations) {
		++idc[r[1]-1];
		od[r[0]-1].emplace_back(r[1]-1);
	}
	vector<int> comT(n, 0);

	queue<int> que;

	for (int i = 0 ; i < n ; ++i) {
		if (idc[i] == 0) {
			que.emplace(i);
			comT[i] = time[i];
		}
	}

	int result = 0;
	while (!que.empty()) {
		int cur = que.front();
		que.pop();
		result = max(result, comT[cur]);

		for (const auto& v : od[cur]) {
			--idc[v];
			comT[v] = max(comT[v], comT[cur] + time[v]);
			if (idc[v] == 0) {
				que.emplace(v);
			}
		}
	}
	return result;
}

