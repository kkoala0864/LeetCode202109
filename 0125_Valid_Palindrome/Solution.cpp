#include <Solution.h>
#include <iostream>
#include <locale>

using std::tolower;

bool isAlphaNum(char c) {
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

bool Solution::isPalindrome(string s) {
	if (s.size() < 2)
		return true;
	int left = 0;
	int right = s.size() - 1;

	while (true) {
		while (left < right && !isAlphaNum(s[left]))
			++left;
		while (right > left && !isAlphaNum(s[right]))
			--right;
		if (left > right)
			return true;
		if (tolower(s[left]) == tolower(s[right])) {
			++left;
			--right;
		} else
			break;
	}

	return false;
}
