#include <Solution.h>

int Solution::smallestNumber(int n) {
	int result = 0;
	for (int i = 0 ; i < 32 ; ++i) {
		result |= 1;
		if (result >= n) return result;
		result = result << 1;
	}
	return -1;
}
