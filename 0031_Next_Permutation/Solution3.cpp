#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::reverse;
using std::swap;

void Solution::nextPermutation3(vector<int> &nums) {
	int tail = nums.size() - 1;
	while (tail > 0 && nums[tail] <= nums[tail - 1])
		--tail;
	if (tail == 0) {
		reverse(nums.begin(), nums.end());
		return;
	}

	int swapIdx = tail - 1;
	tail = nums.size() - 1;
	while (tail > swapIdx && nums[tail] <= nums[swapIdx])
		--tail;
	swap(nums[swapIdx], nums[tail]);
	reverse(nums.begin() + swapIdx + 1, nums.end());
}
