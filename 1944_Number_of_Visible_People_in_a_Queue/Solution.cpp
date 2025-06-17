#include <Solution.h>

// monotonic stack
//
// [10, 6, 8, 5, 11, 9]
// 10
// [0, 0, 0, 0, 0, 0]
// 10, 6
// [1, 0, 0, 0, 0, 0]
// 10, 8
// [2, 1, 0, 0, 0, 0]
// 10, 8, 5
// [2, 1, 1, 0, 0, 0]
// 11
// [3, 1, 2, 1, 0 ,0];
// 11, 9
// [3, 1, 2, 1, 1, 0]
vector<int> Solution::canSeePersonsCount(vector<int> &heights) {
	int size = heights.size();
	vector<int> result(size, 0);

	stack<int> st;
	for (int i = 0 ; i < size ; ++i) {
		while (!st.empty() && heights[st.top()] < heights[i]) {
			++result[st.top()];
			st.pop();
		}
		if (!st.empty()) ++result[st.top()];
		st.emplace(i);
	}
	return result;
}
