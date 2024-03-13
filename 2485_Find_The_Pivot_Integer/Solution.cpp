#include <Solution.h>
#include <iostream>

int Solution::pivotInteger(int n) {
	int sum = (1 + n) * n / 2;

	int cur = 0;
	for (int i = 1 ; i <= n ; ++i) {
		cur += i;
		if ((sum + i - cur) == cur) return i;
	}
	return -1;
}
