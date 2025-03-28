#include <Solution.h>
#include <iostream>
#include <queue>

using std::priority_queue;

long long Solution::maxKelements(vector<int> &nums, int k) {
	long long result = 0;
	priority_queue<long long> pq;

	for (const auto &v : nums)
		pq.emplace(v);

	while (k-- > 0) {
		int v = pq.top();
		result += v;
		v /= 3;
		if ((pq.top() % 3) > 0)
			v += 1;
		pq.pop();
		pq.emplace(v);
	}
	return result;
}
