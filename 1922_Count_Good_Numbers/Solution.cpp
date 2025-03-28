#include <Solution.h>
#include <iostream>

// 9 : 0 ~ 8 : 1 3 5 7 : 0 2 4 6 8
// 8 : 0 ~ 7 : 1 3 5 7 : 0 2 4 6
// 7 : 0 ~ 6 : 1 3 5 : 0 2 4 6
// 4 : 0 ~ 3 : 1 3 : 0 2

long long quickPow(long long x, long long n, long long mod) {
	if (n == 0)
		return 1;
	long long v = quickPow(x, n / 2, mod);
	return n & 1 ? v * v % mod * x % mod : v * v % mod;
}

int Solution::countGoodNumbers(long long n) {
	if (n == 1)
		return 5;

	long long mod = 1e9 + 7;
	long long cnt4 = n / 2;
	long long cnt5 = (n - 1) / 2 + 1;

	return quickPow(4, cnt4, mod) * quickPow(5, cnt5, mod) % mod;
}
