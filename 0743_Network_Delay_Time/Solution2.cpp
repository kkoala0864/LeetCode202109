#include <Solution.h>
#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>

using std::max;
using std::pair;
using std::queue;

int Solution::networkDelayTime2(vector<vector<int>> &times, int n, int k) {
	vector<int> weight(n + 1, INT_MAX);
	weight[k] = 0;
	vector<vector<pair<int, int>>> cost(n + 1, vector<pair<int, int>>());

	for (const auto &t : times)
		cost[t[0]].emplace_back(pair<int, int>(t[1], t[2]));

	queue<int> que;
	que.emplace(k);

	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		for (const auto &ele : cost[cur]) {
			if (weight[ele.first] > (weight[cur] + ele.second)) {
				que.emplace(ele.first);
				weight[ele.first] = weight[cur] + ele.second;
			}
		}
	}

	int result = 0;
	for (int i = 1; i <= n; ++i) {
		if (weight[i] == INT_MAX)
			return -1;
		result = max(result, weight[i]);
	}
	return result;
}
