#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;
using std::sort;

bool check(vector<int> &price, int diff, int k) {
	int last = price[0];
	--k;
	int i = 1;

	while (i < price.size() && k > 0) {
		if (price[i] - last >= diff) {
			last = price[i];
			--k;
		}
		++i;
	}
	return k == 0;
}

int Solution::maximumTastiness(vector<int> &price, int k) {
	sort(price.begin(), price.end());

	int limit = price.back() - price[0] + 1;

	int l = 0, r = limit;
	int mid = 0;
	while (l < r) {
		mid = l + ((r - l) >> 1);
		if (check(price, mid, k)) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	return l - 1;
}
