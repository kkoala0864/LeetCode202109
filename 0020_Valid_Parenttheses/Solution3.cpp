#include <Solution.h>
#include <iostream>
#include <stack>

using std::stack;

bool Solution::isValid3(string s) {
	stack<char> st;
	for (const auto &c : s) {
		if (c == '(' || c == '{' || c == '[')
			st.emplace(c);
		else if (st.empty())
			return false;

		switch (c) {
		case ')':
			if (st.top() == '(')
				st.pop();
			else
				return false;
			break;
		case '}':
			if (st.top() == '{')
				st.pop();
			else
				return false;
			break;
		case ']':
			if (st.top() == '[')
				st.pop();
			else
				return false;
			break;
		default:
			break;
		}
	}
	return st.empty();
}
