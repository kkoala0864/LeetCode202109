#include <Solution.h>
#include <iostream>
#include <stack>

using std::cout;
using std::endl;
using std::stack;

vector<int> Solution::maximumLengthOfRanges(vector<int> &nums) {
	stack<int> st;

	vector<int> result;
	for (int i = 0; i < nums.size(); ++i) {
		while (!st.empty() && nums[st.top()] < nums[i]) {
			st.pop();
		}
		if (st.empty())
			result.emplace_back(i + 1);
		else
			result.emplace_back(i - st.top());
		st.emplace(i);
	}
	st = stack<int>();
	for (int i = nums.size() - 1; i >= 0; --i) {
		while (!st.empty() && nums[st.top()] < nums[i]) {
			st.pop();
		}
		if (st.empty())
			result[i] += (nums.size() - i - 1);
		else
			result[i] += (st.top() - i - 1);
		st.emplace(i);
	}
	return result;
}
