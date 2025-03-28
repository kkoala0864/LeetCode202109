#include <Solution.h>
#include <iostream>

int Solution::addDigits2(int num) {
	if (num == 0)
		return 0;
	return (num % 9) == 0 ? 9 : num % 9;
}
