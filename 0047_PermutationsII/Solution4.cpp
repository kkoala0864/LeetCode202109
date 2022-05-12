#include <Solution.h>
#include <iostream>
#include <unordered_set>

using std::unordered_set;
using std::swap;

void dfs(int idx, vector<int>& nums, vector<vector<int>>& result) {
	if (idx == nums.size()- 1) {
		result.emplace_back(nums);
		return;
	}

	unordered_set<int> flag;
	for (int i = idx ; i < nums.size() ; ++i) {
		if (flag.count(nums[i]) > 0) continue;
		flag.emplace(nums[i]);
		swap(nums[i], nums[idx]);
		dfs(idx + 1, nums, result);
		swap(nums[i], nums[idx]);
	}
}

vector<vector<int>> Solution::permuteUnique4(vector<int>& nums) {
	vector<vector<int>> result;
	dfs(0, nums, result);
	return result;
}
