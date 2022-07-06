#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

int Solution::fib(int n) {
	if (n == 0 || n == 1) return n;
	int pre1 = 0, pre2 = 1;
	int cur = 0;

	for (int i = 2 ; i <= n ; ++i) {
		cur = pre1 + pre2;
		pre1 = pre2;
		pre2 = cur;
	}
	return pre2;
}
