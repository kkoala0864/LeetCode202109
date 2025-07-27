#include <Solution.h>

long long Solution::maximumMedianSum(vector<int>& nums) {
	sort(nums.begin(), nums.end());

	long long result = 0;
	int l = 0, r = nums.size() - 2;
	while (l < r) {
		result += (long long)nums[r];
		++l;
		r -= 2;
	}
	return result;
}
