#include <Solution.h>

bool Solution::isTrionic(vector<int>& nums) {
	int dCnt = 0;
	for (int i = 1 ; i < nums.size() ; ++i) {
		if (nums[i] == nums[i-1]) return false;

		if (nums[i] < nums[i-1]) {
			if (i == 1 || i == nums.size() - 1) return false;
			if (nums[i-1] > nums[i-2]) ++dCnt;
		}
	}
	return dCnt == 1;
}
