#include <Solution.h>

// we just moniter 1 
int Solution::reinitializePermutation(int n) {
	int v = n / 2; // 1 after one operation
	int result = 1;

	while (v != 1) { // means complete all loop
		v = v & 1 ? ((n / 2) + (v - 1) / 2) : v / 2;
		++result;
	}
	return result;
}
