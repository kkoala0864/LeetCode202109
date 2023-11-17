#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;
using std::max;

int Solution::minPairSum(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	int size = nums.size();

	int result = 0;
	for (int i = 0 ; i < size / 2 ; ++i) {
		result = max(result, nums[i] + nums[size - 1 - i]);
	}
	return result;

}
