#include <Solution.h>
#include <iostream>

bool check(const string &s, int i, int j) {
	while (i <= j) {
		if (s[i++] != s[j--])
			return false;
	}
	return true;
}

bool Solution::validPalindrome(string s) {
	int start = 0, end = s.size() - 1;
	while (start <= end) {
		if (s[start] != s[end]) {
			return check(s, start, end - 1) || check(s, start + 1, end);
		}
		++start;
		--end;
	}
	return true;
}
