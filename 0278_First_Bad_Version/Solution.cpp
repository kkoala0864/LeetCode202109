#include <Solution.h>
#include <iostream>

int Solution::firstBadVersion(int n) {
	unsigned int left = 0;
	unsigned int right = n-1;
	unsigned int mid = 0;
	while (left < right) {
		mid = (left + right) / 2;
		if (isBadVersion(mid)) {
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	return isBadVersion(left) ? left : left + 1;
}
