#include <Solution.h>

bool isVowel(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
	       c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

bool Solution::isValid(string word) {
	int vCnt = 0, conCnt = 0;

	if (word.size() < 3) return false;
	for (const auto& c : word) {
		if (!isalpha(c) && !isdigit(c)) return false;
		if (isalpha(c)) {
			if (isVowel(c)) ++vCnt;
			else ++conCnt;
		}
	}
	return vCnt && conCnt;
}
