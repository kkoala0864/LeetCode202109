#include <Solution.h>
#include <iostream>
#include <vector>

long long Solution::minimumReplacement(vector<int>& nums) {
	long long result = 0;

	for (int i = nums.size() - 2 ; i >= 0 ; --i) {
		if (nums[i] <= nums[i+1]) continue;
		int d = max(2, nums[i] / nums[i+1]);
		if ((nums[i] / d + ((nums[i] % d) > 0)) > nums[i+1]) ++d;
		result += (long long)(d - 1);
		nums[i] /= d;
	}
	return result;
}
