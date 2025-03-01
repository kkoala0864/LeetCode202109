#include <Solution.h>
#include <iostream>

// a b c d
// a+b b+c c+d
// a+2b+c b+2c+d
// a+3b+3c+d
//
// a * C(3,0) + b * C(3,1) + c * C(3,2) + d * C(3,3)
// C(3,0) % 10
// C(3,1) % 10
// C(3,2) % 10
// C(3,3) % 10
//
// C(m, n) % p
// (m! / (m-n)!n!) % p
//
// Ferma little constrain
// 1. p is prime => C(m,n) % 2, C(m,n) % 5
// 2. (m-n)!n! can't be divisible by p => Lucas theorem


// C(6, 2) = 6 * 5 / 2 * 1;
long long C(int m, int n) {
	long long v = 1;
	for (int i = 0 ; i < n ; ++i) {
		v *= (long long)(m - i);
		v /= (long long)(i + 1);
	}
	return v;
}

long long lucas(int m, int n, int p) {
	if (n == 0) return 1;
	return (C(m % p, n % p) * lucas(m/p, n/p, p)) % p;
}

bool check(const string& s, int p) {
	int v1 = 0;
	int n = s.size();

	for (int i = 0 ; i < n-1 ; ++i) {
		v1 += (s[i] - '0') * lucas(n-2, i, p);
		v1 %= p;
	}
	int v2 = 0;
	for (int i = 1 ; i < n ; ++i) {
		v2 += (s[i] - '0') * lucas(n-2, i - 1, p);
		v2 %= p;
	}
	return v1 == v2;
}

bool Solution::hasSameDigits(string s) {
	return check(s, 2) && check(s, 5);
}

