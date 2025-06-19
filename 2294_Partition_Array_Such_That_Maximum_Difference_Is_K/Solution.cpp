#include <Solution.h>

int Solution::partitionArray(vector<int>& nums, int k) {
	sort(nums.begin(), nums.end());

	int l = 0;
	int result = 1;
	int last = nums[0];

	for (int i = 1 ; i < nums.size() ; ++i) {
		if (nums[i] - last <= k) continue;
		++result;
		last = nums[i];
	}
	return result;
}
