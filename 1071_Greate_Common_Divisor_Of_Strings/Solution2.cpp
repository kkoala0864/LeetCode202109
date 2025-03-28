#include <Solution.h>
#include <iostream>

string divide2(string &s1, string &s2) {
	if (s1.size() < s2.size())
		swap(s1, s2);
	if (s1 == s2)
		return s1;

	if (s1.substr(0, s2.size()) == s2) {
		string rest = s1.substr(s2.size());
		return divide2(s2, rest);
	} else
		return "";
}

string Solution::gcdOfStrings2(string str1, string str2) {
	return divide2(str1, str2);
}
