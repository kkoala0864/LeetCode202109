#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

int getMaxPalindromeSize(const string& s, int left, int right, int& startIdx) {
	if (left != right && s[left] != s[right]) {
		startIdx = left;
		return 1;
	}
	while (left >= 0 && right < s.size()) {
		if (s[left] != s[right]) break;
		--left;
		++right;
	}
	startIdx = left + 1;
	return right - left - 1;
}

string Solution::longestPalindrome2(string s) {
	string result("");
	int MaxSize = 0;
	int startIdx = 0;
	for (int i = 0 ; i < s.size() ; ++i) {
		int size = getMaxPalindromeSize(s, i, i, startIdx);
		if (size > MaxSize) {
			MaxSize = size;
			result = s.substr(startIdx, size);
		}
		if (i < s.size() - 1) {
			size = getMaxPalindromeSize(s, i, i + 1, startIdx);
			if (size > MaxSize) {
				MaxSize = size;
				result = s.substr(startIdx, size);
			}
		}
	}
	return result;
}

