#include <Solution.h>
#include <iostream>
#include <queue>

using std::priority_queue;

int Solution::makePrefSumNonNegative(vector<int>& nums) {
	priority_queue<int, vector<int>, std::greater<>> pq;

	long sum = 0;
	int result = 0;

	for (const auto& v : nums) {
		if (v < 0) {
			pq.emplace(v);
		}

		sum += (long)v;
		if (sum < 0) {
			sum -= pq.top();
			pq.pop();
			++result;
		}
	}
	return result;
}
