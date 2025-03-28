#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

int Solution::countOrders(int n) {
	long result = 1;
	int mod = 1e9 + 7;

	for (int i = 1; i <= n; ++i) {
		result *= i;
		result = result * (2 * i - 1);
		result %= mod;
	}
	return result;
}
