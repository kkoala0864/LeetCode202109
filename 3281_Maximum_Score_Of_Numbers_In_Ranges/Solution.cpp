#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;
using std::min;
using std::sort;

bool check(vector<int> &s, long long diff, long long d) {
	long long l = s[0];
	for (int i = 1; i < s.size(); ++i) {
		l += diff;
		if (l > (s[i] + d))
			return false;
		l = max(l, (long long)s[i]);
	}
	return true;
}

int Solution::maxPossibleScore(vector<int> &start, int d) {
	sort(start.begin(), start.end());
	long long l = 1, r = start.back() + d - start[0];
	long long mid = 0;

	while (l < r) {
		mid = l + ((r - l) >> 1);

		if (check(start, mid, d)) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	return check(start, l, d) ? l : l - 1;
}
