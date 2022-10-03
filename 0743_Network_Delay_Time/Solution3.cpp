#include <Solution.h>
#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>

using std::priority_queue;
using std::pair;
using std::min;
using std::max;

int Solution::networkDelayTime3(vector<vector<int>>& times, int n, int k) {
	vector<int> minTime(n, INT_MAX);
	vector<vector<pair<int, int>>> needTime(n, vector<pair<int, int>>());

	for (const auto& t : times) needTime[t[0]-1].emplace_back(pair<int, int>(t[1]-1, t[2]));
	priority_queue<pair<int, int>> pq;

	pq.emplace(pair<int, int>(0, k-1));
	minTime[k-1] = 0;
	while (!pq.empty()) {
		int curCost = pq.top().first;
		int curNode = pq.top().second;
		pq.pop();

		if (curCost > minTime[curNode]) continue;

		for (const auto& nextNode : needTime[curNode]) {
			if (curCost + nextNode.second < minTime[nextNode.first]) {
				minTime[nextNode.first] = curCost + nextNode.second;
				pq.emplace(pair<int, int>(minTime[nextNode.first], nextNode.first));
			}
		}
	}
	int result = 0;
	for (const auto& mt : minTime) result = max(result, mt);
	return result == INT_MAX ? -1 : result;
}

