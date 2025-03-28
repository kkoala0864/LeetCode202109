#include <Solution.h>
#include <iostream>
#include <queue>

using std::greater;
using std::pair;
using std::priority_queue;

int Solution::minCostConnectPoints(vector<vector<int>> &points) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
	vector<int> visited(points.size(), false);

	minHeap.push({0, 0});

	int cnt = 0;
	int result = 0;
	while (cnt < points.size()) {
		pair<int, int> cur = minHeap.top();
		minHeap.pop();
		if (visited[cur.second])
			continue;

		visited[cur.second] = true;
		result += cur.first;
		++cnt;
		for (int i = 0; i < visited.size(); ++i) {
			if (visited[i])
				continue;
			int distance = abs(points[i][0] - points[cur.second][0]) + abs(points[i][1] - points[cur.second][1]);
			minHeap.push({distance, i});
		}
	}
	return result;
}
