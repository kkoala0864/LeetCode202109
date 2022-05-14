#include <Solution.h>
#include <iostream>
#include <queue>

using std::max;
using std::min;
using std::pair;
using std::priority_queue;

int Solution::networkDelayTime(vector<vector<int>>& times, int n, int k) {
	vector<vector<pair<int, int>>> adj(101, vector<pair<int, int>>());
	vector<int> arrived(n+1, INT_MAX);
	for (auto& time : times) adj[time[0]].emplace_back(pair<int, int>(time[2], time[1]));

	priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> pq;
	pq.emplace(pair<int, int>(0, k));
	arrived[k] = 0;

	while (!pq.empty()) {
		int cost = pq.top().first;
		int to = pq.top().second;
		pq.pop();
		if (cost > arrived[to]) continue;

		for (const auto& iter : adj[to]) {
			int time = iter.first;
			int neighbor = iter.second;
			if (arrived[neighbor] > time + cost) {
				arrived[neighbor] = time + cost;
				pq.emplace(pair<int, int>(arrived[neighbor], neighbor));
			}
		}
	}

	int result = 0;
	for (int i = 1 ; i <= n ; ++i) result = max(result, arrived[i]);
	return result == INT_MAX ? - 1: result;
}
