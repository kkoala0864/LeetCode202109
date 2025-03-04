#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

bool Solution::checkPowersOfThree(int n) {
	while (n > 0) {
		if (n % 3 == 2) return false;
		n /= 3;
	}
	return true;
}
