#include <Solution.h>

int Solution::minNumberOperations(vector<int> &target) {
	int result = 0;

	stack<int> st;
	st.emplace(0);

	for (const auto& v : target) {
		bool check = false;
		while (!st.empty() && st.top() >= v) {
			check = true;
			st.pop();
		}
		if (!check) result += (v - st.top());
		st.emplace(v);
	}
	return result;
}
