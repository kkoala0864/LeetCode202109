#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::swap;
using std::min;

int Solution::minimumSwap(string s1, string s2) {
	int size = s1.size();
	int xCnt = 0, yCnt = 0;
	for (int i = 0 ; i < size ; ++i) {
		if (s1[i] != s2[i]) {
			s1[i] == 'x' ? ++xCnt : ++yCnt;
		}
	}

	if ((xCnt + yCnt) & 1) return -1;
	// xCnt / 2 : x Same
	// yCnt / 2 : y Same
	// xCnt % 2 + yCnt % 2 : x and y Swap
	int result = xCnt / 2 + yCnt / 2 + (xCnt % 2 + yCnt % 2);
	return result;

}
