#include <Solution.h>
#include <iostream>
#include <stack>

using std::stack;

bool Solution::backspaceCompare(string s, string t) {
	stack<char> ss;
	stack<char> st;

	for (const auto& iter : s) {
		if (iter != '#') {
			ss.emplace(iter);
		} else {
			if (!ss.empty()) ss.pop();
		}
	}

	for (const auto& iter : t) {
		if (iter != '#') {
			st.emplace(iter);
		} else {
			if (!st.empty()) st.pop();
		}
	}

	if (ss.size() != st.size()) return false;
	while (!ss.empty()) {
		if (ss.top() != st.top()) return false;
		ss.pop();
		st.pop();
	}
	return true;
}
