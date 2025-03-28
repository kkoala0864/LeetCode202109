#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::max;
using std::min;

// 0 1 2 3 4 5 6 : 7
// 1 2 3 4 5 6
long long calSum(long long size, long long high) {
	long long l = size >= high ? 1 : (high - size + 1);
	long long len = min(size, high);

	return (l + high) * len >> 1;
}

long long getSum(int n, int index, int mid) {
	int longSide = max(index + 1, n - index);
	int shortSide = min(index + 1, n - index);

	return calSum(longSide, mid) + calSum(shortSide - 1, mid - 1);
}

int Solution::maxValue(int n, int index, int maxSum) {
	int l = 0, r = maxSum;
	int mid = 0;
	maxSum -= n;

	while (l < r) {
		mid = r - ((r - l) >> 1);
		long long v = getSum(n, index, mid);
		if (v <= maxSum) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	return l + 1;
}
