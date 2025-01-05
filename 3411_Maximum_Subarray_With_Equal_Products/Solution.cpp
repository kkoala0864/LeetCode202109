#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <numeric>

using std::max;
using std::gcd;
using std::lcm;

int Solution::maxLength(vector<int>& nums) {
	int result = 1;
	for (int i = 0 ; i < nums.size() ; ++i) {
		long long lv = nums[i], gv = nums[i], prod = nums[i];
		for (int j = i + 1; j < nums.size() ; ++j) {
			prod *= (long long)nums[j];
			lv = lcm(lv, nums[j]);
			gv = gcd(gv, nums[j]);
			if (prod >= 2520 * lv * gv) break;
			if (prod == lv * gv) result = max(result, j - i + 1);
		}
	}
	return result;
}
