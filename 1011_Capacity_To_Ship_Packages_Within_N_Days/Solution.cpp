#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::max;

int needDays(vector<int> &w, int size) {
	int result = 0;
	int cur = 0;
	for (const auto &v : w) {
		if (cur + v > size) {
			++result;
			cur = 0;
		}
		cur += v;
	}
	return cur > 0 ? result + 1 : result;
}

int Solution::shipWithinDays(vector<int> &weights, int days) {
	int r = 0;
	int l = 0;
	for (const auto &w : weights) {
		r += w;
		l = max(l, w);
	}
	int mid = 0;

	while (l < r) {
		int mid = l + ((r - l) >> 1);
		int nd = needDays(weights, mid);
		if (nd <= days) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	return l;
}
