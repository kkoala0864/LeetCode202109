#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;

void dfs(const vector<int>& nums, int idx, vector<vector<int>>& result, vector<int>& local) {
	result.emplace_back(local);
	if (idx >= nums.size()) return;

	int i = idx;
	while (i < nums.size()) {
		local.emplace_back(nums[i]);
		dfs(nums, i + 1, result, local);
		local.pop_back();
		while(i < (nums.size()-1) && nums[i] == nums[i+1]) ++i;
		++i;
	}
}

vector<vector<int>> Solution::subsetsWithDup(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	vector<vector<int>> result;
	vector<int> local;
	dfs(nums, 0, result, local);
	return result;
}
