#include <Solution.h>
#include <iostream>

int Solution::findDuplicate(vector<int>& nums) {
	int fast = nums[0];
	int slow = nums[0];
	do {
		fast = nums[fast];
		slow = nums[nums[slow]];
	} while (fast != slow);

	slow = nums[0];
	while (fast != slow) {
		fast = nums[fast];
		slow = nums[slow];
	}
	return slow;
}
