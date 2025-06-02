#include <Solution.h>

long long comb(long long n) {
	if (n < 0) return 0;
	return ((n + 2) * (n + 1)) / 2;
}

long long Solution::distributeCandies(int n, int limit) {
	int overTake = limit + 1;

	long long result = comb(n);
	result -= 3 * comb(n - overTake);
	result += 3 * comb(n - 2 * overTake);
	result -= comb(n - 3 * overTake);
	return result;
}
