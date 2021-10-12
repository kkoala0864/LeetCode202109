#include <Solution.h>
#include <iostream>

int Solution::guessNumber(int n) {
	unsigned int left = 1;
	unsigned int right = n;
	unsigned int mid = 0;
	while (left <= right) {
		mid = (left + right) / 2;
		if (guess(mid) == 0) return mid;
		else if (guess(mid) < 0) {
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	return -1;
}
