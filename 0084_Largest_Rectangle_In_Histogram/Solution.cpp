#include <Solution.h>
#include <iostream>
#include <stack>
#include <algorithm>

using std::max;
using std::stack;

int Solution::largestRectangleArea(vector<int>& heights) {
	stack<int> st;
	heights.emplace_back(0);
	int ans = 0;
	for (int i = 0 ; i < heights.size() ; ++i) {
		while (!st.empty() && heights[st.top()] > heights[i]) {
			int top = heights[st.top()];
			st.pop();
			int leftEdge = st.empty() ? -1 : st.top();
			ans = max(ans, top * (i - leftEdge - 1));
		}
		st.emplace(i);
	}
	return ans;
}
