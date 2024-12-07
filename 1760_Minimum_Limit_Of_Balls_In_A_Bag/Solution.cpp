#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;
using std::cout;
using std::endl;

int help(const vector<int>& nums, int v) {
	int cnt = 0;
	for (const auto& n : nums) {
		int mod = n % v;
		cnt += (n/v);
		cnt += mod > 0 ? 0 : -1;
	}
	return cnt;
}


int Solution::minimumSize(vector<int>& nums, int maxOperations) {
	int l = 1, r = 0;
	for (const auto& v : nums) r = max(r, v);
	int mid = 0;

	while (l < r) {
		mid = l + ((r - l) >> 1);
		int v = help(nums, mid);
		if (v <= maxOperations) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	return r;
}
