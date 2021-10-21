#include <Solution.h>
#include <iostream>
#include <queue>
using std::priority_queue;
int Solution::findKthLargest(vector<int>& nums, int k) {

	priority_queue<int> maxHeap(nums.begin(), nums.end());

	int val = 0;
	while (k--) {
		val = maxHeap.top();
		maxHeap.pop();
	}
	return val;
}
