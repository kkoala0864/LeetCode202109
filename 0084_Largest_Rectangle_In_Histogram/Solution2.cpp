#include <Solution.h>
#include <iostream>
#include <stack>
#include <algorithm>

using std::max;
using std::stack;

int Solution::largestRectangleArea2(vector<int>& heights) {
	int result = 0;
	stack<int> st;
	heights.emplace_back(0);

	for (int i = 0 ; i < heights.size() ; ++i) {
		while (!st.empty() && heights[st.top()] > heights[i]) {
			int topVal = heights[st.top()];
			st.pop();
			int lastIdx = st.empty() ? -1 : st.top();
			result = max(result, (i - lastIdx - 1) * topVal);
		}
		st.emplace(i);
	}
	return result;
}

