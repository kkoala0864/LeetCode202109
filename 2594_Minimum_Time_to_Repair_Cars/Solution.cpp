#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

// r * n ^ 2 = mid;
// n ^ 2 = mid / r;
// n = sqrt(mid / r);
bool check(vector<int>& ranks, long long mid, long long cars) {
	long long cnt = 0;
	for (const auto& v : ranks) {
		long long cur = mid / v;
		cnt += sqrt(cur);
		if (cnt >= cars) return true;
	}
	return false;
}

long long Solution::repairCars(vector<int>& ranks, int cars) {
	long long mv = 0;
	for (const auto& r : ranks) {
		mv = max(mv, (long long)r);
	}
	long long l = 0, r = ((long long)cars * (long long)cars) * mv;
	long long mid = 0;

	while (l < r) {
		mid = l + ((r-l) >> 1);
		if (check(ranks, mid, cars)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	return l;
}
