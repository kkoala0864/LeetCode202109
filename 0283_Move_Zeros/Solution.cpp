#include <Solution.h>
#include <iostream>

using std::swap;
using std::cout;
using std::endl;
/*
void Solution::moveZeroes(vector<int>& nums) {
	bool change = false;
	do {
		change = false;
		for (int i = 0 ; i < (nums.size() - 1) ; ++i) {
			if ((nums[i] == 0) && (nums[i+1] != 0)) {
				change = true;
				swap(nums[i], nums[i+1]);
			}
		}
	} while (change);

}
void Solution::moveZeroes(vector<int>& nums) {
	int zeroPtr = 0;
	int nonPtr = 0;
	while (zeroPtr < nums.size() && nonPtr < nums.size()) {
		while (zeroPtr < nums.size() && nums[zeroPtr] != 0) ++zeroPtr;
		nonPtr = zeroPtr + 1;
		while (nonPtr < nums.size() && nums[nonPtr] == 0) ++nonPtr;
		if (zeroPtr < nums.size() && nonPtr < nums.size()) swap(nums[zeroPtr], nums[nonPtr]);
	}
}
*/

void Solution::moveZeroes(vector<int>& nums) {
	int nonPtr = 0;

	for (const auto& iter : nums) {
		if (iter != 0) {
			nums[nonPtr] = iter;
			++nonPtr;
		}
	}
	for (int i = nonPtr ; i < nums.size() ; ++i) {
		nums[i] = 0;
	}
}

