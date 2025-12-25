#include <Solution.h>

long long Solution::maximumHappinessSum(vector<int> &happiness, int k) {
	priority_queue<long long> pq;

	for (const auto &h : happiness)
		pq.emplace(h);

	long long result = 0;
	for (long long i = 0; i < k; ++i) {
		if ((pq.top() - i) <= 0)
			break;
		result += (pq.top() - i);
		pq.pop();
	}
	return result;
}
