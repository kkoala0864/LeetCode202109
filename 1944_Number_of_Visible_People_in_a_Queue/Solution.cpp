#include <Solution.h>
#include <iostream>
#include <stack>

using std::stack;
//  3   1   2  1  1   0
// 10 , 6 , 8, 5, 11, 9
// 10, 6
// 10, 8
// 10, 8, 5,
// 11, 9
vector<int> Solution::canSeePersonsCount(vector<int>& heights) {
	stack<int> st;
	vector<int> result(heights.size(), 0);
	st.emplace(0);
	for (int i = 1 ; i < heights.size() ; ++i) {
		while (!st.empty() && heights[st.top()] < heights[i]) {
			++result[st.top()];
			st.pop();
		}
		if (!st.empty()) ++result[st.top()];
		st.emplace(i);
	}
	return result;
}
