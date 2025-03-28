#include <Solution.h>
#include <iostream>

using std::swap;
bool isVowels2(char c) {
	switch (c) {
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
	case 'A':
	case 'E':
	case 'I':
	case 'O':
	case 'U':
		return true;
	default:
		return false;
	}
}

string Solution::reverseVowels2(string s) {
	int l = 0, r = s.size() - 1;
	while (l < r && !isVowels2(s[l]))
		++l;
	while (l < r && !isVowels2(s[r]))
		--r;

	while (l < r) {
		swap(s[l], s[r]);
		++l;
		--r;
		while (l < r && !isVowels2(s[l]))
			++l;
		while (l < r && !isVowels2(s[r]))
			--r;
	}
	return s;
}
