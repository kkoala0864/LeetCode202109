#include <Solution.h>
#include <iostream>
#include <queue>
#include <algorithm>

using std::max;
using std::queue;

int Solution::numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
	vector<int> t(n, 0);
	vector<vector<int>> sub(n, vector<int>());
	for (int i = 0 ; i < n ; ++i) {
		if (manager[i] == -1) continue;
		sub[manager[i]].emplace_back(i);
	}

	queue<int> que;
	que.emplace(headID);
	int result = 0;
	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		for (const auto& s : sub[cur]) {
			t[s] = t[cur] + informTime[cur];
			que.emplace(s);
			result = max(result, t[s]);
		}
	}
	return result;
}
