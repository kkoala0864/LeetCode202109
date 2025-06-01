#include <Solution.h>

long long comb(long long n) {
	if (n < 0) return 0;
	return ((n + 1) * (n + 2)) / 2;
}

// no limit - (over take case)
// no limit - (one person take more than limit) + (two person take more than limit) - (three person take more than limit)
long long Solution::distributeCandies(int n, int limit) {
	long long total = comb(n);

	int overTake = limit + 1;
	total -= 3 * comb(n - overTake);
	total += 3 * comb(n - (2 * overTake));
	total -= comb(n - (3 * overTake));
	return total;
}
