#include <Solution.h>
#include <iostream>

int Solution::passThePillow(int n, int time) {
	int t = time / (n - 1);
	int m = time % (n - 1);
	int direct = t % 2;

	return direct == 0 ? 1 + m : (n - m);
}
