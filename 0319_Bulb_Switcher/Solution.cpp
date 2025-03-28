#include <Solution.h>
#include <iostream>

int Solution::bulbSwitch(int n) {
	int result = 0;
	for (int i = 1; i * i <= n; ++i)
		++result;
	return result;
}
