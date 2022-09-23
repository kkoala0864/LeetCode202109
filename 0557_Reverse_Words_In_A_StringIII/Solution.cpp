#include <Solution.h>
#include <iostream>

using std::swap;

void reverse(string& s, int start, int end) {
	while (start < end) {
		swap(s[start++], s[end--]);
	}
}

string Solution::reverseWords(string s) {
	int idx = 0;
	while (idx < s.size()) {
		if (s[idx] != ' ') {
			int end = idx;
			while (end < s.size() && s[end] != ' ') ++end;
			--end;
			reverse(s, idx, end);
			idx = end;
		}
		++idx;
	}
	return s;
}
