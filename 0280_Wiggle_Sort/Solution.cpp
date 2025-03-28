#include <Solution.h>
#include <iostream>

using std::swap;

void Solution::wiggleSort(vector<int> &nums) {
	for (int i = 0; i < nums.size() - 1; ++i) {
		if (i & 1) {
			if (nums[i] < nums[i + 1])
				swap(nums[i], nums[i + 1]);
		} else {
			if (nums[i] > nums[i + 1])
				swap(nums[i], nums[i + 1]);
		}
	}
}
