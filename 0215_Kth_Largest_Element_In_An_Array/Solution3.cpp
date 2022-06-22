#include <Solution.h>
#include <iostream>
#include <queue>

using std::priority_queue;

int Solution::findKthLargest3(vector<int>& nums, int k) {
	priority_queue<int> heap;
	for (const auto& val : nums) heap.emplace(val);
	while (--k > 0) heap.pop();
	return heap.top();
}
