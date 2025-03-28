#include <Solution.h>
#include <iostream>
#include <unordered_set>
using std::swap;
using std::unordered_set;

void dfs(vector<int> &nums, int idx, vector<vector<int>> &result) {
	if (idx == nums.size()) {
		result.emplace_back(nums);
		return;
	}

	unordered_set<int> flag;
	for (int i = idx; i < nums.size(); ++i) {
		if (flag.find(nums[i]) == flag.end()) {
			flag.emplace(nums[i]);
			swap(nums[i], nums[idx]);
			dfs(nums, idx + 1, result);
			swap(nums[i], nums[idx]);
		}
	}
}

vector<vector<int>> Solution::permuteUnique3(vector<int> &nums) {
	vector<vector<int>> result;
	dfs(nums, 0, result);
	return result;
}
