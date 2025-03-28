#include <Solution.h>
#include <iostream>
#include <queue>

using std::priority_queue;

vector<int> Solution::resultsArray(vector<vector<int>> &queries, int k) {
	priority_queue<int> pq;

	vector<int> result;

	for (const auto &q : queries) {
		int dis = abs(q[0]) + abs(q[1]);

		pq.emplace(dis);

		while (pq.size() > k)
			pq.pop();

		result.emplace_back(pq.size() < k ? -1 : pq.top());
	}
	return result;
}
