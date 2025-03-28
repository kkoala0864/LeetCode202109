#include <Solution.h>
#include <iostream>
#include <vector>
using std::vector;
int Solution::climbStairs(int n) {
	vector<int> number(n + 1, 0);
	number[0] = 1;
	number[1] = 1;
	for (int i = 2; i <= n; ++i) {
		number[i] = number[i - 1] + number[i - 2];
	}
	return number[n];
}
