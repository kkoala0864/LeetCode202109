#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::max;
using std::min;

double check(vector<vector<int>> &squa, double l) {
	double size = 0;
	for (const auto &s : squa) {
		double y = s[1];
		double len = s[2];
		if (y >= l)
			continue;
		size += (min(len, l - y) * len);
	}
	return size;
}

double Solution::separateSquares(vector<vector<int>> &squares) {
	double target = 0;

	double r = 0;
	double l = 1e9;
	double offset = 1 / 1e5;
	for (const auto &s : squares) {
		target += ((double)s[2] * (double)s[2]);
		r = max(r, (double)s[1] + (double)s[2]);
		l = min(l, (double)s[1]);
	}
	target /= 2;
	double mid = 0;

	while (l < r) {
		mid = l + ((r - l) / 2);

		if (mid == l || mid == r)
			break;
		double v = check(squares, mid);
		if (v < target) {
			l = mid + offset;
		} else {
			r = mid;
		}
	}
	return l;
}
