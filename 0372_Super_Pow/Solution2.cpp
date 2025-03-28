#include <Solution.h>
#include <iostream>

int mypow(int base, int n) {
	base %= 1337;

	int result = 1;
	while (n > 0) {
		if (n & 1) {
			result *= base;
			result %= 1337;
		}
		n = n >> 1;
		base *= base;
		base %= 1337;
	}
	return result;
}

int Solution::superPow2(int a, vector<int> &b) {
	int result = 1;

	for (int i = b.size() - 1; i >= 0; --i) {
		result *= mypow(a, b[i]);
		result %= 1337;
		a = mypow(a, 10);
	}
	return result;
}
