#include <Solution.h>
#include <iostream>
#include <stack>
#include <algorithm>

using std::stack;
using std::min;

int Solution::trap2(vector<int>& height) {
	stack<int> st;
	int result = 0;
	int i = 0;
	while (i < height.size() && height[i] == 0) ++i;
	for (; i < height.size() ; ++i) {
		while (!st.empty() && height[i] >= height[st.top()]) {
			int topIdx = st.top();
			st.pop();
			if (st.empty()) break;
			int h = min(height[st.top()], height[i]);
			result += ((h - height[topIdx]) * (i - st.top() - 1));
		}
		st.emplace(i);
	}
	return result;
}
