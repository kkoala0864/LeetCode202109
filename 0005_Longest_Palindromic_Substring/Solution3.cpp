#include <Solution.h>
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::max;

int findMaxPalindrome(string& s, int start, int end, int& size) {
	size = 0;
	while (start >= 0 && end < s.size()) {
		if (s[start] != s[end]) break;
		size = end - start + 1;
		--start;
		++end;
	}
	return start + 1;
}

string Solution::longestPalindrome3(string s) {
	int result = 0;
	string str("");
	int size = 0;
	int start = 0;
	for (int i = 0 ; i < s.size() ; ++i) {
		start = findMaxPalindrome(s, i, i, size);
		if (size > result) {
			result = size;
			str = s.substr(start, size);
		}

		if (i < (s.size() - 1)) {
			start = findMaxPalindrome(s, i , i + 1, size);
			if (size > result) {
				result = size;
				str = s.substr(start, size);
			}
		}
	}
	return str;
}
