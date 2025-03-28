#include <Solution.h>
#include <iostream>
#include <cmath>

bool Solution::isPowerOfThree2(int n) {
	int mod = pow(3, 19);
	return n > 0 ? mod % n == 0 : false;
}
