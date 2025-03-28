#include <Solution.h>
#include <iostream>
#include <climits>

int Solution::reverse3(int x) {
	int result = 0;
	while (x) {
		if (x < 0 && result < INT_MIN / 10)
			return 0;
		if (x > 0 && result > INT_MAX / 10)
			return 0;
		result *= 10;
		if (x < 0 && result < INT_MIN - (x % 10))
			return 0;
		if (x > 0 && result > INT_MAX - (x % 10))
			return 0;
		result += (x % 10);
		x /= 10;
	}
	return result;
}
