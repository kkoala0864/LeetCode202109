#include <Solution.h>
#include <iostream>
#include <climits>

bool check(vector<int>& ribbons, int s, int k) {
	int result = 0;
	for (const auto& r : ribbons) {
		result += (r / s);
	}
	return result >= k;
}

int Solution::maxLength(vector<int>& ribbons, int k) {
	long long sum = 0;
	for (const auto& r : ribbons) sum += r;
	int l = 1, r = sum / k;
	int mid = 0;

	while (l < r) {
		mid = l + ((r-l) / 2);

		if (check(ribbons, mid, k)) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	return check(ribbons, l, k) ? l : l - 1;
}
