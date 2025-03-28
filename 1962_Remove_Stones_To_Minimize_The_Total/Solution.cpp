#include <Solution.h>
#include <iostream>
#include <queue>

using std::priority_queue;

// TC: O((n+k)logn);
int Solution::minStoneSum(vector<int> &piles, int k) {
	priority_queue<int> pq;
	for (const auto &p : piles)
		pq.emplace(p);

	while (k-- > 0) {
		double cur = pq.top();
		pq.pop();

		cur = ceil(cur / 2);
		pq.emplace(cur);
	}

	int result = 0;

	while (!pq.empty()) {
		result += pq.top();
		pq.pop();
	}
	return result;
}
