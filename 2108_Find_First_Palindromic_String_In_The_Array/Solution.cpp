#include <Solution.h>
#include <iostream>

bool isP(const string& s) {
	int l = 0, r = s.size() - 1;
	while (l < r) {
		if (s[l++] != s[r--]) return false;
	}
	return true;
}

string Solution::firstPalindrome(vector<string>& words) {
	for (const auto& w : words) {
		if (isP(w)) return w;
	}
	return "";
}

