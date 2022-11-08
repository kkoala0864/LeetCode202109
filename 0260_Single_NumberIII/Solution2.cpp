#include <Solution.h>
#include <iostream>

vector<int> Solution::singleNumber2(vector<int>& nums) {
	long xorVal = nums[0];

	for (int i = 1 ; i < nums.size() ; ++i) xorVal ^= nums[i];

	long mask = xorVal & (-xorVal);
	long val = xorVal;

	for (const auto& v : nums) {
		if (mask & v) {
			val ^= v;
		}
	}
	return {(int)val, (int)(val ^ xorVal)};
}
