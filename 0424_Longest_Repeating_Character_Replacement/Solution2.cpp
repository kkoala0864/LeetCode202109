#include <Solution.h>
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using std::vector;
using std::max;

int Solution::characterReplacement2(string s, int k) {
	vector<int> charCnt(26, 0);
	int charMaxCnt = 0;
	int start = 0;
	int end = 0;
	int result = 0;
	while (end < s.size()) {
		++charCnt[s[end]-'A'];
		charMaxCnt = max(charCnt[s[end]-'A'], charMaxCnt);
		while (((end - start + 1) - charMaxCnt) > k) {
			--charCnt[s[start]-'A'];
			charMaxCnt = 0;
			for (const auto& iter : charCnt) {
				charMaxCnt = max(iter, charMaxCnt);
			}
			++start;
		}
		result = max(result, end - start + 1);
		++end;
	}
	return result;
}
