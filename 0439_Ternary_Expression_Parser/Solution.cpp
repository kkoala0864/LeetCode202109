#include <Solution.h>
#include <iostream>
#include <stack>

using std::stack;

string Solution::parseTernary(string expression) {
	stack<char> st;

	while (!expression.empty()) {
		char cur = expression.back();
		expression.pop_back();
		if (cur <= '9' && cur >= '0' || cur == 'T' || cur == 'F') {
			st.emplace(cur);
		} else if (cur == '?') {
			char con = expression.back();
			expression.pop_back();
			char t = st.top();
			st.pop();
			char f = st.top();
			st.pop();
			st.emplace(con == 'T' ? t : f);
		}
	}
	return string(1, st.top());
}
