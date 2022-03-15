#include <Solution.h>
#include <iostream>

using std::swap;

void trimSpace(string& s) {
	int i = 0;
	int end = s.size() - 1;
	while (i < s.size() && s[i] == ' ') ++i;
	while (end >= 0 && s[end] == ' ') --end;
	string result;
	while (i <= end) {
		if (s[i] != ' ') result.push_back(s[i]);
		else {
			result.push_back(' ');
			while (i < end && s[i+1] == ' ') ++i;
		}
		++i;
	}
	s = move(result);
}

void rever(string& s, int start, int end) {
	while (start < end) {
		swap(s[start], s[end]);
		++start;
		--end;
	}
}

string Solution::reverseWords2(string s) {
	trimSpace(s);
	rever(s, 0, s.size() - 1);
	int i = 0;
	while (i < s.size()) {
		int end = i;
		while (end < s.size()-1 && s[end+1] != ' ') ++end;
		rever(s, i, end);
		i = end + 2;
	}
	return s;
}
