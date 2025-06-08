#include <Solution.h>

bool Solution::verifyPreorder(vector<int> &preorder) {
	stack<int> st;

	int curMin = INT_MIN;

	for (const auto& v : preorder) {
		if (v < curMin) return false;
		while (!st.empty() && st.top() < v) {
			curMin = st.top();
			st.pop();
		}
		st.emplace(v);
	}
	return true;
}
