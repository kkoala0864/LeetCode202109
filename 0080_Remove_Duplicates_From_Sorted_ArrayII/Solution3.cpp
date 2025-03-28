#include <Solution.h>
#include <iostream>

int Solution::removeDuplicates3(vector<int> &nums) {
	if (nums.empty())
		return 0;

	int resultIdx = 1;
	int cnt = 1;
	for (int i = 1; i < nums.size(); ++i) {
		if (nums[i] == nums[i - 1] && cnt >= 2)
			continue;
		if (nums[i] != nums[i - 1])
			cnt = 0;
		nums[resultIdx] = nums[i];
		++cnt;
		++resultIdx;
	}
	return resultIdx;
}
