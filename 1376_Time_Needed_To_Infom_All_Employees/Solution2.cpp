#include <Solution.h>
#include <iostream>
#include <queue>
#include <algorithm>

using std::max;
using std::queue;

int Solution::numOfMinutes2(int n, int headID, vector<int> &manager, vector<int> &informTime) {
	vector<vector<int>> out(n, vector<int>());
	vector<int> time(n, 0);

	for (int i = 0; i < n; ++i) {
		if (manager[i] != -1)
			out[manager[i]].emplace_back(i);
	}

	queue<int> que;
	que.emplace(headID);
	int result = 0;

	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		for (const auto &v : out[cur]) {
			time[v] = time[cur] + informTime[cur];
			result = max(result, time[v]);
			que.emplace(v);
		}
	}
	return result;
}
