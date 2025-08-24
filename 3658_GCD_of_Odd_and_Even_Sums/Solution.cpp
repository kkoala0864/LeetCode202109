#include <Solution.h>

int getGCD(int lhs, int rhs) {
	if (lhs < rhs) swap(lhs, rhs);
	if (rhs == 0) return lhs;
	lhs %= rhs;
	return getGCD(rhs, lhs);
}

int Solution::gcdOfOddEvenSums(int n) {
	int odd = 0, even = 0;
	for (int i = 1 ; i <= (2 * n) ; ++i) {
		if (i & 1) odd += i;
		else even += i;
	}
	return getGCD(odd, even);
}
