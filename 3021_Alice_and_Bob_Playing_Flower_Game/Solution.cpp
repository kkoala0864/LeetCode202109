#include <Solution.h>

// total number must be odd
long long Solution::flowerGame(int n, int m) {
	long long result = 0;

	long long ne = n / 2;
	long long no = (n / 2) + (n & 1);
	long long me = m / 2;
	long long mo = (m / 2) + (m & 1);
	result = (ne * mo) + (no * me);
	return result;
}
