#include <Solution.h>
#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>

using std::queue;
using std::pair;
using std::min;

vector<int> Solution::shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
	vector<vector<int>> stepCnt(2, vector<int>(n, INT_MAX));
	vector<vector<vector<int>>> edge(2, vector<vector<int>>(n, vector<int>()));

	for (const auto& e : redEdges) edge[0][e[0]].emplace_back(e[1]);
	for (const auto& e : blueEdges) edge[1][e[0]].emplace_back(e[1]);

	queue<pair<int, int>> que, next;
	int step = 1;
	que.emplace(pair<int, int>(0, 0));
	que.emplace(pair<int, int>(1, 0));
	stepCnt[0][0] = 0;
	stepCnt[1][0] = 0;

	while (!que.empty()) {
		int curNode = que.front().second;
		int curColor = que.front().first;
		que.pop();

		int nextColor = curColor ^ 1;
		for (const auto& nextNode : edge[nextColor][curNode]) {
			if (stepCnt[nextColor][nextNode] != INT_MAX) continue;
			stepCnt[nextColor][nextNode] = step;
			next.emplace(pair<int, int>(nextColor, nextNode));
		}

		if (que.empty()) {
			++step;
			que = move(next);
		}
	}

	vector<int> result;
	for (int i = 0 ; i < n ; ++i) {
		int val = min(stepCnt[0][i], stepCnt[1][i]);
		result.emplace_back(val == INT_MAX ? -1 : val);
	}
	return result;
}
