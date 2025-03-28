#include <Solution.h>
#include <iostream>
#include <locale>
using std::cout;
using std::endl;

bool Solution::isPalindrome2(string s) {
	int start = 0;
	int end = s.size() - 1;
	while (start < end && !isalnum(s[start]))
		++start;
	while (end >= start && !isalnum(s[end]))
		--end;
	while (start <= end) {
		if (tolower(s[start]) != tolower(s[end]))
			return false;
		++start;
		--end;
		while (start < end && !isalnum(s[start]))
			++start;
		while (end >= start && !isalnum(s[end]))
			--end;
	}
	return true;
}
