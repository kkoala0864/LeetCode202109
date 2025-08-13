#include <Solution.h>

int Solution::sortPermutation(vector<int>& nums) {
	int result = INT_MAX;
	for (int i = 0 ; i < nums.size() ; ++i) {
		if (nums[i] != i) result &= nums[i];
	}
	return result == INT_MAX ? 0 : result;

}
