#include <Solution.h>
#include <iostream>
#include <unordered_set>
using std::swap;
using std::unordered_set;

void permutation2(vector<int> &nums, vector<vector<int>> &result, int idx) {
	if (idx == (nums.size() - 1)) {
		result.emplace_back(nums);
		return;
	}

	unordered_set<int> flag;
	for (int i = idx; i < nums.size(); ++i) {
		if (flag.find(nums[i]) == flag.end()) {
			flag.emplace(nums[i]);
			swap(nums[idx], nums[i]);
			permutation2(nums, result, idx + 1);
			swap(nums[idx], nums[i]);
		}
	}
}

vector<vector<int>> Solution::permuteUnique2(vector<int> &nums) {
	vector<vector<int>> result;
	permutation2(nums, result, 0);
	return result;
}
