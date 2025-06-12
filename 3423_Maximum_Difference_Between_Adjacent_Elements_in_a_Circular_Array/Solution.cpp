#include <Solution.h>

int Solution::maxAdjacentDistance(vector<int>& nums) {
	int result = INT_MIN;
	int size = nums.size();
	for (int i = 0 ; i < size ; ++i) {
		result = max(result, abs(nums[i] - nums[(i+1) % size]));
	}
	return result;
}
