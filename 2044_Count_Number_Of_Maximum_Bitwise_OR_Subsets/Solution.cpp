#include <Solution.h>
#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

void dfs(vector<int> &nums, int idx, int curV, int &result, int mor) {
	if (curV == mor) {
		result += pow(2, (int)nums.size() - idx);
		return;
	}
	if (idx == nums.size())
		return;

	dfs(nums, idx + 1, curV | nums[idx], result, mor);
	dfs(nums, idx + 1, curV, result, mor);
}

int Solution::countMaxOrSubsets(vector<int> &nums) {
	int mor = 0;
	for (const auto &v : nums)
		mor = mor | v;

	int result = 0;
	dfs(nums, 0, 0, result, mor);
	return result;
}
