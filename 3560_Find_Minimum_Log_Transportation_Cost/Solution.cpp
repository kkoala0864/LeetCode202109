#include <Solution.h>

long long Solution::minCuttingCost(int n, int m, int k) {
	long long result = 0;

	if (n >= k) {
		result += ((long long)(n - k) * (long long)k);
	}
	if (m >= k) {
		result += ((long long)(m - k) * (long long)k);
	}
	return result;
}
