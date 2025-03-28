#include <Solution.h>
#include <iostream>
#include <queue>

using std::priority_queue;

bool Solution::isPossible(vector<int> &target) {
	if (target.size() == 1)
		return target[0] == 1;
	priority_queue<int> pq;

	long long sum = 0;
	for (const auto &val : target) {
		pq.emplace(val);
		sum += val;
	}

	while (sum > 1 && pq.top() > sum / 2) {
		int largest = pq.top();
		pq.pop();
		int rest = sum - largest;
		if (rest <= 1)
			return rest;
		int prevLarge = largest % rest;
		pq.emplace(prevLarge);
		sum = prevLarge + rest;
	}

	return sum == target.size();
}
