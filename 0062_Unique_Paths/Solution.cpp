#include <Solution.h>
#include <iostream>

int Combination(int total, int num) {
	if (num == 0) return 1;
	unsigned long long int divide = 1, beDivide = 1;
	for (int i = 0 ; i < num ; ++i) {
		beDivide *= total--;
		divide *= (i + 1);
	}
	return beDivide / divide;
}


int Solution::uniquePaths(int m, int n) {
	int totalStep = (m - 1) + (n - 1);
	if (m > n) {
		return Combination(totalStep, n - 1);
	} else {
		return Combination(totalStep, m - 1);
	}
}
