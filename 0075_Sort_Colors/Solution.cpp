#include <Solution.h>
//  i1                i2
// 2 1 2 0 0 2 1 2 0 0 1
// 1 1 2 0 0 2 1 2 0 0 2
void Solution::sortColors(vector<int> &nums) {
	int i0 = 0;
	int i2 = nums.size() - 1;
	int i = 0;

	while (i <= i2) {
		if (nums[i] == 0) {
			swap(nums[i], nums[i0++]);
			// if there exists 2 in left part, it must be swap to right part
			// so left part is all 0 or 1
			// and if we swap 0 with i0 when i meet 0, swap to i is must be 1
			// because all 0 is swap to index before i0
			++i;
		} else if (nums[i] == 2) swap(nums[i], nums[i2--]);
		else ++i;
	}
}
