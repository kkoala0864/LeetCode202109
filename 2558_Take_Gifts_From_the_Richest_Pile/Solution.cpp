#include <Solution.h>
#include <iostream>
#include <queue>
#include <cmath>

using std::priority_queue;

long long Solution::pickGifts(vector<int>& gifts, int k) {
	priority_queue<int> pq;

	long long result = 0;

	for (const auto& g : gifts) {
		pq.emplace(g);
		result += g;
	}

	while (k-- > 0) {
		int c = pq.top();
		pq.pop();
		int r = sqrt(c);
		result -= (long long)(c-r);
		pq.emplace(r);
	}
	return result;
}
