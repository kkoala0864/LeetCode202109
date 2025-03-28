#include <Solution.h>
#include <iostream>
#include <queue>

using std::priority_queue;

int Solution::findKthLargest2(vector<int> &nums, int k) {
	priority_queue<int> heap;
	for (const auto &iter : nums)
		heap.emplace(iter);
	while (k-- > 1)
		heap.pop();
	return heap.top();
}
