#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <vector>

using std::max;
using std::vector;

int Solution::longestSubsequence(string s, int k) {
	int sum = 0, pow = 1, cnt = 0;
	int i = s.size() - 1;
	for (; i >= 0 && (sum + pow) <= k; --i) {
		if (s[i] == '1') {
			sum += pow;
		}
		++cnt;
		pow <<= 1;
	}

	for (; i >= 0; --i)
		if (s[i] == '0')
			++cnt;
	return cnt;
}
