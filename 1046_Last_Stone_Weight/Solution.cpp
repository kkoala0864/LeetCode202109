#include <Solution.h>
#include <iostream>
#include <queue>

using std::priority_queue;

int Solution::lastStoneWeight(vector<int> &stones) {
	priority_queue<int> maxHeap;
	for (const auto &iter : stones)
		maxHeap.emplace(iter);

	while (maxHeap.size() > 1) {
		int first = maxHeap.top();
		maxHeap.pop();
		int second = maxHeap.top();
		maxHeap.pop();
		int next = abs(first - second);
		if (next > 0)
			maxHeap.emplace(next);
	}
	return maxHeap.empty() ? 0 : maxHeap.top();
}
