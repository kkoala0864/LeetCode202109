#include <Solution.h>
#include <iostream>
#include <queue>

using std::priority_queue;
using std::pair;

int Solution::leastInterval(vector<char>& tasks, int n) {
	priority_queue<pair<int, int>> pq;
	vector<int> cnt(26, 0);
	for (const auto& t : tasks) ++cnt[t-'A'];

	for (int i = 0 ; i < 26 ; ++i) {
		if (cnt[i] > 0) pq.emplace(pair<int, int>(cnt[i], i));
	}
	vector<int> sch(26, -n);
	vector<pair<int, int>> cache;

	int T = 0;
	while (!pq.empty()) {
		while (!pq.empty() && (T - sch[pq.top().second]) < (n+1)) {
			cache.emplace_back(pq.top());
			pq.pop();
		}
		if (!pq.empty()) {
			auto cur = pq.top();
			pq.pop();
			sch[cur.second] = T;
			--cur.first;
			if (cur.first > 0) pq.emplace(cur);
		}
		while (!cache.empty()) {
			pq.emplace(cache.back());
			cache.pop_back();
		}
		++T;
	}
	return T-1;
}
