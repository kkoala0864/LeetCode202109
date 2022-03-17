#include <Solution.h>
#include <iostream>
#include <stack>

using std::stack;

int dfs(const string& s, int& idx) {
	int result = 0;
	while (idx < s.size()) {
		if (s[idx] == '(') {
			result += dfs(s, ++idx);
		} else {
			++idx;
			result = result == 0 ? 1 : 2 * result;
			return result;
		}
	}
	return result;
}

int Solution::scoreOfParentheses(string s) {
	int idx = 0;
	return dfs(s, idx);
}
