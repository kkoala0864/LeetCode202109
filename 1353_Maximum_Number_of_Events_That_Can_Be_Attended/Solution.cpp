#include <Solution.h>

int Solution::maxEvents(vector<vector<int>> &events) {
	priority_queue<int, vector<int>, greater<>> pq;
	sort(events.begin(), events.end());

	int result = 0;
	int ei = 0;

	for (int i = 1 ; i <= 1e5 ; ++i) {
		while (ei < events.size() && events[ei][0] <= i) {
			pq.emplace(events[ei++][1]);
		}

		while (!pq.empty() && pq.top() < i) {
			pq.pop();
		}

		if (!pq.empty()) {
			pq.pop();
			++result;
		}
	}
	return result;
}
