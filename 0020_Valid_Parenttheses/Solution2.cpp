#include <Solution.h>
#include <iostream>
#include <stack>

using std::stack;

bool Solution::isValid2(string s) {
	stack<char> st;
	for (const auto& ch : s) {
		switch (ch) {
			case '{':
			case '(':
			case '[':
				st.emplace(ch);
				break;
			case '}':
				if (st.empty() || st.top() != '{') return false;
				st.pop();
				break;
			case ')':
				if (st.empty() || st.top() != '(') return false;
				st.pop();
				break;
			case ']':
				if (st.empty() || st.top() != '[') return false;
				st.pop();
				break;
			default:
				break;
		}
	}
	return st.empty();
}
