#include <Solution.h>
#include <iostream>

bool dfs(int local, vector<bool> &visited, const vector<int> &nums, int idx, int k, int target) {
	if (local == target) {
		--k;
		idx = 0;
		local = 0;
	}
	if (k == 0)
		return true;

	bool result = false;
	for (int i = idx; i < nums.size(); ++i) {
		if (visited[i] || (local + nums[i] > target))
			continue;
		visited[i] = true;
		result = result || dfs(local + nums[i], visited, nums, i + 1, k, target);
		visited[i] = false;
	}
	return result;
}

bool Solution::canPartitionKSubsets2(vector<int> &nums, int k) {
	int sum = 0;
	for (const auto &iter : nums)
		sum += iter;
	if (sum % k)
		return false;

	vector<bool> visited(nums.size(), false);
	int target = sum / k;
	return dfs(0, visited, nums, 0, k, target);
}
