#include <Solution.h>
#include <iostream>

vector<int> Solution::getMaximumXor(vector<int> &nums, int maximumBit) {
	vector<int> result(nums.size(), 0);

	int mask = (1 << maximumBit) - 1;
	int cur = 0;
	for (int i = 0; i < nums.size(); ++i) {
		cur = cur ^ nums[i];
		int k = (cur ^ mask);
		result[nums.size() - i - 1] = k;
	}
	return result;
}
