#include <Solution.h>

int Solution::mostBooked(int n, vector<vector<int>> &meetings) {
	priority_queue<pair<long, long>, vector<pair<long, long>>, std::greater<>> pq, m;
	priority_queue<int, vector<int>, std::greater<>> free;

	vector<int> cnt(n, 0);
	for (int i = 0; i < meetings.size(); ++i) {
		m.emplace(pair<int, int>(meetings[i][0], meetings[i][1]));
	}

	for (int i = 0; i < n; ++i)
		free.emplace(i);

	while (!m.empty()) {
		long start = m.top().first;
		long end = m.top().second;
		long offset = end - start;
		m.pop();

		while (!pq.empty() && pq.top().first <= start) {
			free.emplace(pq.top().second);
			pq.pop();
		}

		long curT = 0;
		long r = 0;
		if (free.empty()) {
			curT = pq.top().first;
			r = pq.top().second;
			pq.pop();
		} else {
			curT = -1;
			r = free.top();
			free.pop();
		}

		curT = max(curT, start);
		++cnt[r];
		pq.emplace(pair<long, long>(curT + offset, r));
	}

	int result = -1;
	int maxCnt = 0;
	for (int i = 0; i < n; ++i) {
		if (maxCnt < cnt[i]) {
			maxCnt = cnt[i];
			result = i;
		}
	}
	return result;
}
