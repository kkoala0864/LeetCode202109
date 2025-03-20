#include <Solution.h>
#include <iostream>
#include <stack>

using std::stack;

int Solution::minNumberOperations(vector<int>& target) {
	stack<int> st;

	int result = 0;
	st.emplace(0);
	for (const auto& v : target) {
		bool check = false;
		while (!st.empty() && st.top() > v) {
			check = true;
			st.pop();
		}
		if (!check) result += (v - st.top());
		if (st.top() != v) st.emplace(v);
	}
	return result;
}
