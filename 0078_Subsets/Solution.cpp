#include <Solution.h>
#include <iostream>

void dfs(const vector<int> &nums, int idx, vector<vector<int>> &result, vector<int> &local) {
	result.emplace_back(local);
	if (idx == nums.size())
		return;

	for (int i = idx; i < nums.size(); ++i) {
		local.emplace_back(nums[i]);
		dfs(nums, i + 1, result, local);
		local.pop_back();
	}
}

vector<vector<int>> Solution::subsets(vector<int> &nums) {
	vector<vector<int>> result;
	vector<int> local;
	dfs(nums, 0, result, local);
	return result;
}
