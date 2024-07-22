#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>

using std::queue;
using std::pair;
using std::min;

int Solution::minimumCost(int n, vector<vector<int>>& highways, int discounts) {
	vector<vector<int>> costs(n, vector<int>(n, 0));
	vector<vector<int>> con(n, vector<int>());

	for (const auto& h : highways) {
		costs[h[0]][h[1]] = h[2];
		costs[h[1]][h[0]] = h[2];
		con[h[1]].emplace_back(h[0]);
		con[h[0]].emplace_back(h[1]);
	}

	queue<pair<int, int>> que;
	vector<vector<int>> minCost(n, vector<int>(discounts + 1, INT_MAX));

	for (int i = 0 ; i <= discounts ; ++i) minCost[0][i] = 0;
	que.emplace(pair<int, int>(0, discounts));

	while (!que.empty()) {
		int curNode = que.front().first;
		int curDC = que.front().second;
		que.pop();

		for (const auto& nextNode : con[curNode]) {
			int nextCost = minCost[curNode][curDC] + costs[curNode][nextNode];
			if (minCost[nextNode][curDC] > nextCost) {
				minCost[nextNode][curDC] = nextCost;
				que.emplace(pair<int, int>(nextNode, curDC));
			}
			if (curDC > 0) {
				int nextCostWithDC = minCost[curNode][curDC] + (costs[curNode][nextNode] / 2);
				if (minCost[nextNode][curDC - 1] > nextCostWithDC) {
					minCost[nextNode][curDC - 1] = nextCostWithDC;
					que.emplace(pair<int, int>(nextNode, curDC - 1));
				}
			}
		}
	}
	int result = INT_MAX;
	for (const auto& v : minCost.back()) {
		result = min(result, v);
	}
	return result == INT_MAX ? -1 : result;

}
