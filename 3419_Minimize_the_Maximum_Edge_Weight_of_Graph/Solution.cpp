#include <Solution.h>
#include <iostream>
#include <queue>
#include <algorithm>

using std::cout;
using std::endl;
using std::max;
using std::pair;
using std::priority_queue;

int Solution::minMaxWeight(int n, vector<vector<int>> &edges, int threshold) {
	vector<vector<pair<int, int>>> id(n, vector<pair<int, int>>());
	for (const auto &e : edges) {
		id[e[1]].emplace_back(pair<int, int>(e[2], e[0]));
	}

	vector<bool> visited(n, false);

	int result = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> pq;
	pq.push({0, 0});

	while (!pq.empty()) {
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (visited[cur])
			continue;
		visited[cur] = true;
		result = max(result, cost);
		for (const auto &n : id[cur]) {
			if (visited[n.second])
				continue;
			pq.push(n);
		}
	}
	for (const auto &v : visited)
		if (!v)
			return -1;
	return result;
}
