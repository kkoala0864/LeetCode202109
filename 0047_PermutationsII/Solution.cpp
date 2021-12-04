#include <Solution.h>
#include <iostream>
using std::swap;

void permutation(vector<int>& nums, vector<vector<int>>& result, int idx) {
	if (idx == nums.size() -1) {
		result.emplace_back(nums);
		return;
	}

	vector<bool> flag(21, false);
	for (int i = idx ; i < nums.size() ; ++i) {
		if (!flag[nums[i]+10]) {
			flag[nums[i]+10] = true;
			swap(nums[i], nums[idx]);
			permutation(nums, result, idx+1);
			swap(nums[i], nums[idx]);
		}
	}
}

vector<vector<int>> Solution::permuteUnique(vector<int>& nums) {
	vector<vector<int>> result;
	permutation(nums, result, 0);
	return result;
}
