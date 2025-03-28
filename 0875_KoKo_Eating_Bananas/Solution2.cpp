#include <Solution.h>
#include <iostream>
#include <climits>

int getHour(vector<int> &p, int t) {
	int result = 0;
	for (const auto &v : p) {
		result += (v / t);
		if (v % t > 0)
			result += 1;
	}
	return result;
}

int Solution::minEatingSpeed2(vector<int> &piles, int h) {
	int l = 1, r = INT_MAX;
	int mid = 0;

	while (l < r) {
		mid = l + ((r - l) >> 1);
		int nh = getHour(piles, mid);

		if (nh <= h) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	return l;
}
