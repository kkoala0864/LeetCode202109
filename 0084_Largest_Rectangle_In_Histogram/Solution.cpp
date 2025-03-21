#include <Solution.h>
#include <iostream>
#include <stack>
#include <algorithm>

using std::max;
using std::stack;
using std::cout;
using std::endl;

int Solution::largestRectangleArea(vector<int>& heights) {
	stack<int> st;
	int n = heights.size();
	vector<int> preSmaller(heights.size(), -1);
	vector<int> nextSmaller(heights.size(), n);

	for (int i = 0 ; i < heights.size() ; ++i) {
		while (!st.empty() && heights[st.top()] >= heights[i]) {
			nextSmaller[st.top()] = i;
			st.pop();
		}
		if (!st.empty()) {
			preSmaller[i] = st.top();
		}
		st.emplace(i);
	}
	int result = 0;
	for (int i = 0 ; i < n ; ++i) {
		result = max(result, (nextSmaller[i] - preSmaller[i] - 1) * heights[i]);
	}
	return result;
}
