#include <Solution.h>

vector<int> Solution::findBuildings(vector<int>& heights) {
	vector<int> st;

	for (int i = 0 ; i < heights.size() ; ++i) {
		while (!st.empty() && heights[st.back()] <= heights[i]) {
			st.pop_back();
		}
		st.emplace_back(i);
	}
	return st;
}
