#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <queue>

using std::priority_queue;
using std::sort;
using std::pair;

vector<vector<int>> Solution::getSkyline(vector<vector<int>>& buildings) {
	vector<vector<int>> edges;
	for (int i = 0 ; i < buildings.size() ; ++i) {
		edges.push_back({buildings[i][0], i});
		edges.push_back({buildings[i][1], i});
	}

	sort(edges.begin(), edges.end());
	priority_queue<pair<int, int>> live;
	vector<vector<int>> result;
	int idx = 0;
	while (idx < edges.size()) {
		int curX = edges[idx][0];

		while (idx < edges.size() && edges[idx][0] == curX) {
			int b = edges[idx][1];
			if (buildings[b][0] == curX) {
				int right = buildings[b][1];
				int height = buildings[b][2];
				live.emplace(pair<int, int>(height, right));
			}
			++idx;
		}

		while (!live.empty() && live.top().second <= curX) live.pop();

		int curHeight = live.empty() ? 0 : live.top().first;
		if (result.empty() || result.back()[1] != curHeight) result.push_back({curX, curHeight});
	}
	return result;
}
