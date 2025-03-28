#include <Solution.h>
#include <iostream>
#include <queue>

using std::cout;
using std::endl;
using std::priority_queue;

int Solution::minOperations(vector<int> &nums, int k) {
	priority_queue<long, vector<long>, std::greater<>> pq;

	for (const auto &v : nums) {
		if (v >= k)
			continue;
		pq.emplace(v);
	}

	int result = 0;
	while (pq.size() > 1) {
		long v1 = pq.top();
		pq.pop();
		long v2 = pq.top();
		pq.pop();
		long v = v1 * 2 + v2;
		if (v < k) {
			pq.emplace(v);
		}
		++result;
	}
	return result + (pq.empty() ? 0 : 1);
}
