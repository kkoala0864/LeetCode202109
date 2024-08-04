#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <stack>

using std::stack;

vector<int> Solution::nextGreaterElements(vector<int>& nums) {
	vector<int> result(nums.size(), -1);
	stack<int> st;
	int size = nums.size();
	st.emplace(0);
	for (int i = 0 ; i < size * 2 ; ++i) {
		int idx = i % size;
		while (!st.empty() && nums[idx] > nums[st.top()]) {
			result[st.top()] = nums[idx];
			st.pop();
		}
		if (result[idx] == -1) st.emplace(idx);
	}
	return result;
}

