#include <Solution.h>
#include <iostream>

int Solution::totalMoney(int n) {
	int m = n / 7;
	int mod = n % 7;

	int result = 0;
	if (m > 0) {
		result += (28 * m + 7 * (m * (m - 1) / 2));
	}
	for (int i = 0; i < mod; ++i) {
		result += ++m;
	}
	return result;
}
