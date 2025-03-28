#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <queue>

using std::max;
using std::priority_queue;

int Solution::maxEvents(vector<vector<int>> &events) {
	sort(events.begin(), events.end());
	priority_queue<int, vector<int>, std::greater<int>> pq;

	int result = 0;
	int ei = 0;
	for (int d = 1; d <= 1e5; ++d) {
		while (ei < events.size() && events[ei][0] <= d) {
			pq.emplace(events[ei][1]);
			++ei;
		}

		while (!pq.empty() && pq.top() < d) {
			pq.pop();
		}

		if (!pq.empty()) {
			pq.pop();
			++result;
		}
	}

	return result;
}
