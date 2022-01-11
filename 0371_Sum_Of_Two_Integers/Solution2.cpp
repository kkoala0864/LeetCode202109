#include <Solution.h>
#include <iostream>

int Solution::getSum2(int a, int b) {
	unsigned int carry = b;
	unsigned int result = a;
	while (carry != 0) {
		unsigned int tmp = result ^ carry;
		carry = (result & carry) << 1;
		result = tmp;
	}
	return (int) result;
}
