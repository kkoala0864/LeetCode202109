#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int check(vector<int>& nums, int mid) {
	int result = 0;
	for (const auto& v : nums) {
		result += (v / mid);
		if (v % mid) ++result;
	}
	return result;
}

int Solution::smallestDivisor(vector<int>& nums, int threshold) {
	int l = 1, r = 1e6;
	int mid = 0;

	while (l < r) {
		mid = l + ((r-l) >> 1);
		int v = check(nums, mid);
		if (v > threshold) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	return l;
}
