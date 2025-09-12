#include <Solution.h>

bool isVowel(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool Solution::doesAliceWin(string s) {
	int cnt = 0;
	for (const auto& c : s) {
		if (isVowel(c)) return true;
	}
	return false;
}
