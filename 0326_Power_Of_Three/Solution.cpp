#include <Solution.h>
#include <iostream>

bool Solution::isPowerOfThree(int n) {
	if (n <= 0) return false;
	while ( n > 1 ) {
		if (n % 3) return false;
		if (n /= 3;
	}
	return true;
}

