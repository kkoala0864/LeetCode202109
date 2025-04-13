#include <Solution.h>
#include <iostream>

// 0 1 2 3 4 => even: 3 odd :2
// 0 1 2 3 => even : 2 odd : 2

long long quickPow(long long x, long long n, long long mod) {
	if (n == 0) return 1;
	long long v = quickPow(x, n / 2, mod);
	long long vv = v * v % mod;
	return n & 1 ? vv * x % mod : vv;
}

int Solution::countGoodNumbers(long long n) {
	long long evenCnt = (n >> 1) + (n & 1);
	long long oddCnt = (n >> 1);

	long long mod = 1e9 + 7;
	long long result = quickPow(5, evenCnt, mod);
	result *= quickPow(4, oddCnt, mod);
	result %= mod;
	return result;
}
