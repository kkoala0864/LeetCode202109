#include <Solution.h>

bool Solution::checkDivisibility(int n) {
	int sum = 0;
	int pro = 1;
	int tmp = n;
	while (tmp > 0) {
		sum += tmp % 10;
		pro *= tmp % 10;
		tmp /= 10;
	}
	return n % (sum + pro) == 0;
}
