#include <Solution.h>
#include <iostream>

int Solution::brokenCalc(int startValue, int target) {
	int result = 0;
	while (startValue != target) {
		if (target > startValue) {
			if (target & 1) {
				target += 1;
			} else {
				target /= 2;
			}
		} else {
			return result + (startValue - target);
		}
		++result;
	}
	return result;
}
