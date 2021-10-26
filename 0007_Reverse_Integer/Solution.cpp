#include <Solution.h>
#include <iostream>
#include <climits>

int Solution::reverse(int x) {
	int n = x;
	int result = 0;
	while (n) {
		int mod = n % 10;
		if (result > INT_MAX/10 || ((result == INT_MAX/10) && (mod > 7))) return 0;
		if (result < INT_MIN/10 || ((result == INT_MIN/10) && (mod < -8))) return 0;
		n /= 10;
		result = result * 10 + mod;
	}
	return result;
}
