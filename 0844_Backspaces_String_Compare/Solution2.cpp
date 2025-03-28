#include <Solution.h>
#include <iostream>
#include <stack>

using std::stack;

bool Solution::backspaceCompare2(string s, string t) {
	stack<char> st, tt;
	for (const auto &c : s) {
		if (c == '#') {
			if (!st.empty())
				st.pop();
		} else {
			st.emplace(c);
		}
	}
	for (const auto &c : t) {
		if (c == '#') {
			if (!tt.empty())
				tt.pop();
		} else {
			tt.emplace(c);
		}
	}
	if (st.size() != tt.size())
		return false;
	else {
		while (!st.empty()) {
			if (st.top() != tt.top())
				return false;
			st.pop();
			tt.pop();
		}
	}
	return true;
}
