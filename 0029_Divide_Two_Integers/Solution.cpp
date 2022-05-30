#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

int Solution::addingPowerOfTwo(int dividend, int divisor) {
	int HALF_INT_MIN = -1073741824;

	if (dividend == INT_MIN && divisor == -1) return INT_MAX;

	int negatives = 2;
	if (dividend > 0) {
		--negatives;
		dividend = -dividend;
	}
	if (divisor > 0) {
		--negatives;
		divisor = -divisor;
	}
	vector<int> doubles, powersOfTwo;
	int powerOfTwo = -1;
	while (divisor >= dividend) {
		doubles.emplace_back(divisor);
		powersOfTwo.emplace_back(powerOfTwo);
		if (divisor < HALF_INT_MIN) break;

		divisor += divisor;
		powerOfTwo += powerOfTwo;
	}
	int quotient = 0;
	for (int i = doubles.size() - 1 ; i >= 0 ; --i) {
		if (doubles[i] >= dividend) {
			quotient += powersOfTwo[i];
			dividend -= doubles[i];
		}
	}

	if (negatives != 1) return -quotient;
	return quotient;
}

int Solution::divide(int dividend, int divisor) {
	if (dividend == 0) return 0;
	long long bediv = abs(dividend);
	long long div = abs(divisor);

	long long cnt = 0;
	if (divisor == 1) {
		cnt = dividend;
	} else {
		while (bediv > 0) {
			bediv -= div;
			++cnt;
		}
		if (bediv < 0) --cnt;
	}
	if ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)) return cnt > INT_MAX ? INT_MAX : cnt;
	else return -cnt < INT_MIN ? INT_MIN : -cnt;
}
