#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;

vector<int> Solution::sortArrayByParity(vector<int> &nums) {
	vector<int> result(nums.size(), 0);
	int eIdx = 0, oIdx = nums.size() - 1;
	for (int i = 0; i < nums.size(); ++i) {
		if (nums[i] & 1) {
			result[oIdx] = nums[i];
			--oIdx;
		} else {
			result[eIdx] = nums[i];
			++eIdx;
		}
	}
	return result;
}
