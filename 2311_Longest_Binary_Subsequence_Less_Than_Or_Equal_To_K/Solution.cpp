#include <Solution.h>

int Solution::longestSubsequence(string s, int k) {
	int size = s.size();
	int offset = 0;
	int result = 0;
	long long sum = 0;
	for (int i = size - 1 ; i >= 0 ; --i, ++offset) {
		if (s[i] == '0') {
			++result;
			continue;
		}

		if (offset < 32) {
			if ((sum | ((long long)1 << offset)) <= (long long)k) {
				sum = sum | 1 << offset;
				++result;
			}
		} else {
			continue;
		}
	}
	return result;

}
