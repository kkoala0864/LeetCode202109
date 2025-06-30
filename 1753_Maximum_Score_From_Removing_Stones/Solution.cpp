#include <Solution.h>

int Solution::maximumScore(int a, int b, int c) {
	priority_queue<int> pq;
	pq.emplace(a);
	pq.emplace(b);
	pq.emplace(c);

	int result = 0;
	while (pq.size() >= 2) {
		int p1 = pq.top();
		pq.pop();
		int p2 = pq.top();
		pq.pop();
		++result;
		if (p1 > 1) {
			pq.emplace(p1-1);
		}
		if (p2 > 1) {
			pq.emplace(p2-1);
		}
	}
	return result;
}
