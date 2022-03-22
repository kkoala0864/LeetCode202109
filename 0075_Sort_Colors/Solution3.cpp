#include "Solution.h"

using std::swap;

void Solution::sortColors3(vector<int>& nums) {
	int iter = 0;
	int idx0 = 0;
	int idx2 = nums.size() - 1;
	while (iter <= idx2) {
		if (nums[iter] == 0) {
			swap(nums[iter], nums[idx0]);
			++idx0;
			++iter;
		} else if (nums[iter] == 2) {
			swap(nums[iter], nums[idx2]);
			--idx2;
		} else {
			++iter;
		}
	}
}
