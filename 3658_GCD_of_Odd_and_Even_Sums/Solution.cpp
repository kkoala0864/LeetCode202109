#include <Solution.h>

int getGCD(int lhs, int rhs) {
	if (lhs < rhs) swap(lhs, rhs);
	if (rhs == 0) return lhs;
	lhs %= rhs;
	return getGCD(rhs, lhs);
}

int diffSum(int start, int end, int len) {
	return (start + end) * len / 2;
}

int Solution::gcdOfOddEvenSums(int n) {
	int odd = diffSum(1, 2 * n - 1, n), even = diffSum(2, 2 * n, n);
	return getGCD(odd, even);
}
