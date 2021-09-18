#include <Solution.h>
#include <iostream>
#include <stack>

using std::stack;

bool Solution::isValid(string s) {
	stack<char> st;
	for (const auto iter : s) {
		switch (iter) {
			case '{':
			case '[':
			case '(':
				st.push(iter);
				break;
			case '}':
				if (st.empty() || st.top() != '{') return false;
				st.pop();
				break;
			case ']':
				if (st.empty() || st.top() != '[') return false;
				st.pop();
				break;
			case ')':
				if (st.empty() || st.top() != '(') return false;
				st.pop();
				break;
			default:
				return false;
		}
	}
	return st.empty();
}
