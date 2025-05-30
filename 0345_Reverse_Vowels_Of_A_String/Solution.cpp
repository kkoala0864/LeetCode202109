#include <Solution.h>
#include <iostream>

using std::swap;
bool isVowels(char c) {
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

string Solution::reverseVowels(string s) {
	int l = 0, r = s.size() - 1;
	while (l < r) {
		if (isVowels(s[l]))
			break;
		++l;
	}
	while (r > l) {
		if (isVowels(s[r]))
			break;
		--r;
	}

	while (l < r) {
		swap(s[l++], s[r--]);
		while (l < r) {
			if (isVowels(s[l]))
				break;
			++l;
		}
		while (r > l) {
			if (isVowels(s[r]))
				break;
			--r;
		}
	}
	return s;
}
