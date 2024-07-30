#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <vector>

using std::min;
using std::pair;
using std::vector;

int Solution::minimumDeletions(string s) {
	int bCnt = 0;
	int result = 0;

	for (const auto& c : s) {
		if (c == 'b') ++bCnt;
		else {
			// remove 'a' or keep 'a'
			result = min(result + 1, bCnt);
		}
	}
	return result;
}
