#include <Solution.h>
#include <iostream>
#include <queue>
#include <algorithm>

using std::max;
using std::queue;

int Solution::numOfMinutes3(int n, int headID, vector<int> &manager, vector<int> &informTime) {
	vector<vector<int>> outdegree(n, vector<int>());
	vector<int> time(n, 0);

	for (int i = 0; i < manager.size(); ++i) {
		if (manager[i] != -1) {
			outdegree[manager[i]].emplace_back(i);
		}
	}

	queue<int> que;
	que.emplace(headID);
	int result = 0;
	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		for (const auto &n : outdegree[cur]) {
			time[n] = time[cur] + informTime[cur];
			result = max(time[n], result);
			que.emplace(n);
		}
	}
	return result;
}
