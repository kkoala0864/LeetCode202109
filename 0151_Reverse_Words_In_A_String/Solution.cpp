#include <Solution.h>
#include <iostream>

using std::swap;

void reverse(string &s, int left, int right) {
	while (left < right) {
		swap(s[left++], s[right--]);
	}
}

void trim(string &s) {
	if (s[0] == ' ') {
		int leading = 0;
		while (s[leading] == ' ')
			++leading;
		s = s.substr(leading);
	}
}

string Solution::reverseWords(string s) {
	trim(s);
	reverse(s, 0, s.size() - 1);
	string result = "";
	int idx = 0;
	while (idx < s.size()) {
		if (s[idx] != ' ') {
			int end = idx;
			while (s[end] != ' ' && end < s.size())
				++end;
			reverse(s, idx, end - 1);
			result.append(s.substr(idx, end - idx));
			idx = end;
		} else {
			result.append(" ");
			while (s[idx] == ' ') {
				idx++;
			}
		}
	}
	trim(result);
	return result;
}
