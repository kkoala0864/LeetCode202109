#include <Solution.h>
#include <iostream>
#include <stack>
#include <algorithm>

using std::max;
using std::min;
using std::stack;

int Solution::findUnsortedSubarray(vector<int> &nums) {
	stack<int> front, tail;
	int start = nums.size(), end = 0;
	for (int i = 0; i < nums.size(); ++i) {
		while (!front.empty() && nums[i] < nums[front.top()]) {
			start = min(start, front.top());
			front.pop();
		}
		front.emplace(i);
		while (!tail.empty() && nums[nums.size() - i - 1] > nums[tail.top()]) {
			end = max(end, tail.top());
			tail.pop();
		}
		tail.emplace(nums.size() - i - 1);
	}
	return start == nums.size() ? 0 : abs(end - start + 1);
}
