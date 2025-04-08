#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <climits>


int Solution::integerReplacement(int n) {
	unordered_map<long long, int> minCost;
	minCost[n] = 0;

	priority_queue<long long> pq;

	pq.emplace(n);
	while (!pq.empty()) {
		long long cur = pq.top();
		pq.pop();

		if (cur == 1 || cur < 0) continue;

		if (cur & 1) {
			if (minCost.count(cur + 1) == 0 || ((minCost[cur] + 1) < (minCost[cur + 1]))) {
				minCost[cur+1] = minCost[cur] + 1;
				pq.emplace(cur+1);
			}
			if (minCost.count(cur-1) == 0 || ((minCost[cur] + 1) < (minCost[cur-1]))) {
				minCost[cur-1] = minCost[cur] + 1;
				pq.emplace(cur-1);
			}
		} else {
			if (minCost.count(cur/2) == 0 || ((minCost[cur] + 1) < minCost[cur / 2])) {
				minCost[cur/2] = minCost[cur] + 1;
				pq.emplace(cur/2);
			}
		}
	}
	return minCost[1];
}
