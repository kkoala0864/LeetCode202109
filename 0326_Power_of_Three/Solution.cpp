#include <Solution.h>

// n = 3 ^ x1;
// (3 ^ 19) = 3 ^ (x1 + x2) = (3 ^ x1) * (3 ^ x2);
// (3 ^ 19) / (3 ^ x1) = (3 ^ x2);
// (3 ^ 19) % n = 0;
bool Solution::isPowerOfThree(int n) {
	int mxVof3 = 1162261467;
	return n > 0 && (mxVof3 % n) == 0;
}
