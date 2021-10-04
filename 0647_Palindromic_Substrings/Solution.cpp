#include <Solution.h>
#include <iostream>

void isPalindromic(const string& s, int start, int end, int& cnt) {
	while (start >=0 && end < s.size()) {
		if (s[start] == s[end]) {
			++cnt;
			--start;
			++end;
		} else return;
	}
}

int Solution::countSubstrings(string s) {
	int size = s.size();
	int cnt = 0;
	for (int i = 0 ; i < size ; ++i) {
		isPalindromic(s, i, i, cnt);
		isPalindromic(s, i, i+1, cnt);
	}
	return cnt;
}
