#include <Solution.h>
#include <iostream>
#include <queue>
#include <algorithm>

using std::min;
using std::priority_queue;

int Solution::minimumDeviation(vector<int> &nums) {
	priority_queue<int> heap;

	int minVal = INT_MAX;
	for (const auto &iter : nums) {
		int val = iter & 1 ? iter * 2 : iter;
		heap.emplace(val);
		minVal = min(minVal, val);
	}

	int result = INT_MAX;
	while (true) {
		int val = heap.top();
		result = min(result, val - minVal);
		if (val & 1)
			break;
		heap.pop();
		minVal = min(minVal, val >> 1);
		heap.emplace(val >> 1);
	}
	return result;
}
