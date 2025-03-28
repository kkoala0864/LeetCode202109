#include <Solution.h>
#include <iostream>

void dfs(const vector<int> &nums, vector<vector<int>> &result, vector<int> &local, int idx) {
	result.emplace_back(local);

	for (int i = idx; i < nums.size(); ++i) {
		local.emplace_back(nums[i]);
		dfs(nums, result, local, i + 1);
		local.pop_back();
	}
}

vector<vector<int>> Solution::subsets2(vector<int> &nums) {
	vector<vector<int>> result;
	vector<int> local;
	dfs(nums, result, local, 0);
	return result;
}
