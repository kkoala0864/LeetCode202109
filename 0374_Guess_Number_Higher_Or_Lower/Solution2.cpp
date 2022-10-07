#include <Solution.h>
#include <iostream>

int Solution::guessNumber2(int n) {
	int l = 1, r = n;
	int mid = 0;

	while (l < r) {
		mid = l + ((r - l) >> 1);
		int result = guess(mid);
		if (result <= 0) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	return l;
}
