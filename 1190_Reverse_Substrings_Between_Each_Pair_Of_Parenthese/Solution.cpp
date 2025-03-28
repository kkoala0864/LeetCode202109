#include <Solution.h>
#include <iostream>

string recur(string &s, int &idx) {
	if (idx == s.size())
		return "";

	string result;
	for (; idx < s.size(); ++idx) {
		if (s[idx] == ')') {
			reverse(result.begin(), result.end());
			return result;
		} else if (s[idx] == '(') {
			++idx;
			result += recur(s, idx);
		} else {
			result.push_back(s[idx]);
		}
	}
	return result;
}

string Solution::reverseParentheses(string s) {
	int idx = 0;
	return recur(s, idx);
}
