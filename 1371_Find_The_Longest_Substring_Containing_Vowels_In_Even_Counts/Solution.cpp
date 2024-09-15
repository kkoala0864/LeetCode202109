#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using std::unordered_map;
using std::max;

bool isVowel(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int Solution::findTheLongestSubstring(string s) {
	int result = 0;
	int l = 0;
	int mask = 0;
	unordered_map<int, int> m;

	for (int i = 0 ; i < s.size() ; ++i) {
		if (isVowel(s[i])) {
			mask ^= (1 << (s[i] - 'a'));
		}
		if (mask == 0) {
			result = max(result, i + 1);
		} else if (m.count(mask)) {
			result = max(result, i - m[mask]);
		}
		if (m.count(mask) == 0) m[mask] = i;
	}
	return result;
}
