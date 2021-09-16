#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int IsPalindromic(string &s, int first, int second, int& startIndex) {
	if (first != second && s[first] != s[second]) {
		startIndex = first;
		return 1;
	};

	int leftIter = first == second ? first - 1 : first;
	int rightIter = first == second ?  second + 1 : second;

	while (leftIter >= 0 && rightIter < s.size()) {
		if (s[leftIter] != s[rightIter]) {
			break;
		}
		--leftIter;
		++rightIter;
	}
	startIndex = leftIter + 1;

	return rightIter - leftIter - 1;
}


string Solution::longestPalindrome(string s) {
	if (s.size() < 2) return s;
	int maxIndex(0);
	int maxLen(0);
	for (int i = 0 ; i < s.size() ; ++i) {
		int tmpIndex(0);
		int single = IsPalindromic(s, i, i, tmpIndex);
		if (single > maxLen) {
			maxIndex = tmpIndex;
			maxLen = single;
		}
		if (i < (s.size() - 1)) {
			int two = IsPalindromic(s, i, i + 1, tmpIndex);
			if (two > maxLen) {
				maxIndex = tmpIndex;
				maxLen = two;
			}
		}
	}
	return s.substr(maxIndex, maxLen);
}

