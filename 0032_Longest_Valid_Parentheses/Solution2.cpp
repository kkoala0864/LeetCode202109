#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <stack>

using std::max;
using std::stack;

int Solution::longestValidParentheses2(string s) {
	stack<int> st;
	int result = 0;
	int iter = 0;
	while (iter < s.size()) {
		if (s[iter] == '(') {
			st.emplace(iter);
		} else {
			if (!st.empty()) {
				s[iter] = '0';
				s[st.top()] = '0';
				st.pop();
			}
		}
		++iter;
	}
	int local = 0;
	for (const auto& iter : s) {
		if (iter == '0') ++local;
		else {
			result = max(result, local);
			local = 0;
		}
	}
	result = max(result, local);
	return result;
}
