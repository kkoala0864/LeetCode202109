#include <Solution.h>
#include <iostream>
#include <string>

bool isPalin(int v) {
	string s = to_string(v);
	if (s.size() & 1) return false;
	int l = 0, r = s.size() - 1;

	int ls = 0, rs = 0;
	while (l < r) {
		ls += (s[l++] - '0');
		rs += (s[r--] - '0');
	}
	return ls == rs;
}

int Solution::countSymmetricIntegers(int low, int high) {
	int result = 0;

	for (int i = low ; i <= high ; ++i) {
		result += isPalin(i);
	}
	return result;
}
