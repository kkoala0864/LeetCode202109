#include <Solution.h>
#include <iostream>
#include <stack>

int Solution::minInsertions(string s) {
	int offset = 0;
	int result = 0;
	for (int i = 0 ; i < s.size() ; ++i) {
		if (s[i] == '(') {
			++offset;
		} else {
			if (i + 1 == s.size() || s[i+1] != ')') {
				++result;
			} else {
				++i;
			}
			--offset;
		}
		if (offset < 0) {
			result += (-offset);
			offset = 0;
		}
	}
	result += (offset * 2);
	return result;
}
