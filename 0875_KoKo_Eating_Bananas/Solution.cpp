#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;

int geth(const vector<int>& piles, int k) {
	int ret = 0;
	for (const auto& iter : piles) {
		if (iter % k) {
			ret += (iter / k) + 1;
		} else {
			ret += (iter / k);
		}
	}
	return ret;
}


int Solution::minEatingSpeed(vector<int>& piles, int h) {
	sort(piles.begin(), piles.end());
	if (piles.size() == h) return piles.back();

	int start = 1, end = piles.back(), mid = 0;
	while (start <= end) {
		mid = (start + end) / 2;
		int ph = geth(piles, mid);
		if (ph <= h) {
			end = mid - 1;
		} else {
			start = mid + 1;
		}
	}
	return start;
}
