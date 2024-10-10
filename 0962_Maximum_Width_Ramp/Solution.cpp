#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <stack>

using std::stack;
using std::max;

int Solution::maxWidthRamp(vector<int>& nums) {
	stack<int> st;

	for (int i = 0 ; i < nums.size() ; ++i) {
		if (st.empty() || nums[st.top()] > nums[i]) {
			st.emplace(i);
		}
	}
	int result = 0;

	for (int i = nums.size() - 1 ; i > 0 ; --i) {
		while (!st.empty() && nums[st.top()] <= nums[i]) {
			result = max(result, i - st.top());
			st.pop();
		}
	}
	return result;
}
