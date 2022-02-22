#include <Solution.h>
#include <iostream>

int Solution::twoEggDrop(int n) {
	int cnt = 0;
	while (n > 0) {
		++cnt;
		n -= cnt;
	}
	return cnt;
}
