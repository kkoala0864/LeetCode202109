#include <Solution.h>
#include <iostream>
//     n  t
// [ 1, 2, 2, 3, 4, 5, 5, 6]
//

int Solution::removeDuplicates3(vector<int>& nums) {
	if (nums.empty()) return 0;
	int iter = 1;

	for (int i = 1 ; i < nums.size() ; ++i) {
		while (i < nums.size() && nums[i] == nums[iter-1]) ++i;
		if (i < nums.size()) nums[iter++] = nums[i];
	}
	return iter;
}
