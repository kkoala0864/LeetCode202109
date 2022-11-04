#include <Solution.h>
#include <iostream>
#include <queue>

using std::priority_queue;
using std::greater;
using std::pair;
using std::cout;
using std::endl;

int Solution::minCostConnectPoints2(vector<vector<int>>& points) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.emplace(pair<int, int>(0, 0));

	int m = points.size();
	vector<bool> visited(m, false);
	int result = 0;
	int cnt = 0;

	while (cnt < m) {
		int curNode = pq.top().second;
		int curCost = pq.top().first;
		pq.pop();

		if (visited[curNode]) continue;
		visited[curNode] = true;
		++cnt;
		result += curCost;

		for (int i = 0 ; i < m ; ++i) {
			if (visited[i]) continue;
			int cost = abs(points[i][0] - points[curNode][0]) + abs(points[i][1] - points[curNode][1]);
			pq.emplace(pair<int, int>(cost, i));
		}
	}
	return result;

}
