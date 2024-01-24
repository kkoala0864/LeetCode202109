#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <queue>

using std::priority_queue;

int Solution::connectSticks(vector<int>& sticks) {
	priority_queue<int, vector<int>, std::greater<int>> pq;
	for (const auto& s : sticks) {
		pq.emplace(s);
	}

	int result = 0;
	while (pq.size() > 1) {
		int n1 = pq.top();
		pq.pop();
		int n2 = pq.top();
		pq.pop();
		int v = n1 + n2;
		result += v;
		pq.emplace(v);
	}
	return result;
}
