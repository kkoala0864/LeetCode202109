#include <Solution.h>
#include <iostream>
#include <queue>

using std::pair;
using std::queue;

int Solution::secondMinimum(int n, vector<vector<int>> &edges, int time, int change) {
	vector<vector<int>> od(n, vector<int>());

	for (const auto &e : edges) {
		od[e[0] - 1].emplace_back(e[1] - 1);
		od[e[1] - 1].emplace_back(e[0] - 1);
	}

	vector<vector<int>> minTime(n, vector<int>());
	minTime[0].emplace_back(0);
	queue<pair<int, int>> que;

	que.emplace(pair<int, int>(0, 0));

	while (!que.empty()) {
		int curNode = que.front().first;
		int curTime = que.front().second;
		que.pop();

		int cv = curTime / change;
		if (cv & 1) {
			curTime = (cv + 1) * change;
		}
		for (const auto &nextNode : od[curNode]) {
			if (minTime[nextNode].size() == 2)
				continue;
			if (!minTime[nextNode].empty() && minTime[nextNode].back() == (curTime + time))
				continue;
			minTime[nextNode].emplace_back(curTime + time);
			que.emplace(pair<int, int>(nextNode, curTime + time));
		}
		if (minTime[n - 1].size() == 2)
			break;
	}
	return minTime[n - 1].back();
}
