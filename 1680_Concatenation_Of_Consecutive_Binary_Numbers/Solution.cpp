#include <Solution.h>
#include <iostream>

int Solution::concatenatedBinary(int n) {
	long result = 0;
	long mod = 1e9 + 7;
	long pow2 = 2;
	for (int i = 1 ; i <= n ; ++i) {
		result *= pow2;
		result += i;
		result %= mod;
		if (i == pow2 - 1) pow2 *= 2;
	}
	return result;
}
