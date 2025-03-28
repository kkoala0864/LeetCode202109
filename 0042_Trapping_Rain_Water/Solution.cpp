#include <Solution.h>
#include <iostream>
#include <stack>
#include <algorithm>

using std::min;
using std::stack;

int Solution::trap(vector<int> &height) {
	stack<int> st;
	int result = 0;
	for (int i = 0; i < height.size(); ++i) {
		while (!st.empty() && height[i] > height[st.top()]) {
			int top = st.top();
			st.pop();
			if (st.empty())
				break;
			int distance = i - st.top() - 1;
			int bounded_height = min(height[st.top()], height[i]) - height[top];
			result += distance * bounded_height;
		}
		st.emplace(i);
	}
	return result;
}
