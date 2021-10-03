#include <Solution.h>
#include <iostream>

int Solution::getSum(int a, int b) {
	unsigned int c = a, d = b;
	unsigned int result = c;
	while (d > 0) {
		result = c ^ d;
		d = (c & d) << 1;
		c = result;
	}
	return (int)result;
}
