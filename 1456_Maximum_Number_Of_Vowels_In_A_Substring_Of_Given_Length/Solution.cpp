#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

bool isV(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int Solution::maxVowels(string s, int k) {
	int result = 0;
	int vCnt = 0;

	for (int i = 0; i < s.size(); ++i) {
		if (i >= k) {
			if (isV(s[i - k]))
				--vCnt;
		}
		if (isV(s[i]))
			++vCnt;
		result = max(result, vCnt);
	}
	return result;
}
