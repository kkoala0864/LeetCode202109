#include <Solution.h>
#include <iostream>

int Solution::minSwaps(string s) {
	int start = -1, end = s.size();
	int sCnt = 0, eCnt = 0;
	int result = 0;
	while (start < end) {
		while (sCnt >= 0 && start < end) {
			++start;
			if (s[start] == '[') ++sCnt;
			else --sCnt;
		}
		while (eCnt >= 0 && start < end) {
			--end;
			if (s[end] == ']') ++eCnt;
			else --eCnt;
		}
		if (start != end) {
			++result;
			eCnt = 1;
			sCnt = 1;
		}
	}
	return result;
}
