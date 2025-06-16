#include <Solution.h>

int Solution::maximumDifference(vector<int>& nums) {
	int preMin = nums[0];
	int result = -1;

	for (int i = 1 ; i < nums.size() ; ++i) {
		if (preMin < nums[i]) {
			result = max(result, nums[i] - preMin);
		}
		preMin = min(preMin, nums[i]);
	}
	return result;

}
