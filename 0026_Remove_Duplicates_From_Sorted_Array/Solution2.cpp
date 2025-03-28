#include <Solution.h>
#include <iostream>
//     n  t
// [ 1, 2, 2, 3, 4, 5, 5, 6]
//

int Solution::removeDuplicates2(vector<int> &nums) {
	if (nums.empty())
		return 0;
	int i = 0, iter = 1;
	while (iter < nums.size()) {
		if (nums[iter] != nums[i]) {
			++i;
			nums[i] = nums[iter];
		}
		++iter;
	}
	return i + 1;
}
