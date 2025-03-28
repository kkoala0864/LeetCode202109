#include "Solution.h"

using std::swap;
void Solution::sortColors2(vector<int> &nums) {
	int idx0 = 0;
	int idx2 = nums.size() - 1;
	int iter = 0;
	while (iter <= idx2) {
		if (nums[iter] == 0) {
			swap(nums[idx0], nums[iter]);
			++iter;
			++idx0;
		} else if (nums[iter] == 2) {
			swap(nums[idx2], nums[iter]);
			--idx2;
		} else {
			++iter;
		}
	}
}
