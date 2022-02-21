#include <Solution.h>
#include <iostream>

int Solution::guessNumber2(int n) {
	int start = 1, end = n;
	int mid = 0;
	int ret = 0;
	while (start <= end) {
		mid = ((end - start) / 2) + start;
		ret = guess(mid);
		if (ret == 0) return mid;
		else if (ret == 1) start = mid + 1;
		else end = mid - 1;
	}
	return 0;
}
