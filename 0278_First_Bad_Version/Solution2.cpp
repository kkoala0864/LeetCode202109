#include <Solution.h>
#include <iostream>

int Solution::firstBadVersion2(int n) {
	int start = 1, end = n;
	int mid = 0;
	while (start <= end) {
		mid = (end - start) / 2 + start;
		if (isBadVersion(mid)) {
			end = mid - 1;
		} else {
			start = mid + 1;
		}
	}
	return start;
}
