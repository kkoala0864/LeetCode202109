#include <Solution.h>
#include <iostream>
//     n  t
// [ 1, 2, 2, 3, 4, 5, 5, 6]
//

int Solution::removeDuplicates(vector<int> &nums) {
	if (nums.size() < 2)
		return nums.size();
	int index = 0;
	int iter = 1;
	while (iter < nums.size()) {
		if (nums[index] != nums[iter]) {
			++index;
			nums[index] = nums[iter];
		}
		++iter;
	}
	return index + 1;
}
