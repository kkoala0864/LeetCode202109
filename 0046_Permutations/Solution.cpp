#include <Solution.h>
#include <iostream>
using std::swap;

void permutation(vector<int>& nums, vector<vector<int>>& result, int idx) {
	if (idx == (nums.size() - 1)) {
		result.emplace_back(nums);
		return;
	}

	for (int i = idx ; i < nums.size() ; ++i) {
		swap(nums[idx], nums[i]);
		permutation(nums, result, idx + 1);
		swap(nums[idx], nums[i]);
	}
}

vector<vector<int>> Solution::permute(vector<int>& nums) {
	vector<vector<int>> result;
	permutation(nums, result, 0);
	return result;
}
