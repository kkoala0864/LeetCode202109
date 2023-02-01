#include <Solution.h>
#include <iostream>

void divide(string& s1, string& s2) {
	int size = s2.size();
	if (size == 0) return;
	if (s1.substr(0, size) == s2) {
		s1 = s1.substr(size);
		if (s1.size() < s2.size()) swap(s1, s2);
		divide(s1, s2);
	}
}

string Solution::gcdOfStrings(string str1, string str2) {
	if (str1.size() < str2.size()) swap(str1, str2);
	divide(str1, str2);
	return str2.empty() ? str1 : "";
}
