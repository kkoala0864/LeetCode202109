#include <Solution.h>
#include <iostream>
#include <queue>

using std::priority_queue;

int Solution::lastStoneWeight2(vector<int> &stones) {
	priority_queue<int> pq;
	for (const auto &v : stones)
		pq.emplace(v);

	while (pq.size() > 1) {
		int first = pq.top();
		pq.pop();
		int second = pq.top();
		pq.pop();

		if (first == second)
			continue;
		else
			pq.emplace(first - second);
	}
	return pq.empty() ? 0 : pq.top();
}
