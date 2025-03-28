#include <Solution.h>
#include <iostream>

using std::swap;
vector<int> Solution::findDisappearedNumbers(vector<int> &nums) {
	for (int i = 0; i < nums.size(); ++i) {
		int idx = nums[i] - 1;
		while ((idx != i) && (nums[i] != nums[idx])) {
			swap(nums[i], nums[idx]);
			idx = nums[i] - 1;
		}
	}
	vector<int> result;
	for (int i = 0; i < nums.size(); ++i) {
		if (nums[i] != i + 1) {
			result.emplace_back(i + 1);
		}
	}
	return result;
}
