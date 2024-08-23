#include <Solution.h>
#include <iostream>

int Solution::findComplement(int num) {
	int result = 0;
	int base = 1;
	while (num > 0) {
		if ((num & 1) == 0) {
			result |= base;
		}
		base = base << 1;
		num = num >> 1;
	}
	return result;
}
