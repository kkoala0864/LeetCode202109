#include <Solution.h>
#include <iostream>

string Solution::getSmallestString(int n, int k) {
	string result(n, ' ');
	int end = n - 1;
	while (k >= 1 && end >= 0) {
		if (k > 26) {
			result[end] = 'z';
			k -= 26;
			--end;
		} else {
			result[end] = k + 'a' - 1;
			k = 0;
		}
	}
	if (end < 0) return result;

	int i = 0;
	for (int i = 0 ; i < end ; ++i) {
		result[i] = 'a';
		--result[end];
		if (result[end]-'a' == -1) ++end;
	}
	return result;
}
