#include <Solution.h>
#include <iostream>
using std::swap;

void dfs(vector<int> &nums, int idx, vector<vector<int>> &result) {
	if (idx == nums.size()) {
		result.emplace_back(nums);
		return;
	}

	for (int i = idx; i < nums.size(); ++i) {
		swap(nums[i], nums[idx]);
		dfs(nums, idx + 1, result);
		swap(nums[i], nums[idx]);
	}
}

vector<vector<int>> Solution::permute2(vector<int> &nums) {
	vector<vector<int>> result;
	dfs(nums, 0, result);
	return result;
}
