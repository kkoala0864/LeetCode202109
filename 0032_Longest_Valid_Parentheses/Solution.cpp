#include <Solution.h>
#include <iostream>
#include <stack>
#include <algorithm>
#include <climits>

using std::max;
using std::stack;

int Solution::longestValidParentheses(string s) {
	int result = 0;
	int cnt = 0;
	int size = s.size();
	stack<int> st;

	for (int i = 0; i < size; ++i) {
		if (s[i] == '(') {
			st.emplace(i);
		} else {
			if (!st.empty()) {
				s[st.top()] = s[i] = '*';
				st.pop();
			}
		}
	}

	for (int i = 0; i < size; ++i) {
		if (s[i] == '*')
			++cnt;
		else {
			result = max(result, cnt);
			cnt = 0;
		}
	}
	result = max(result, cnt);
	return result;
}
