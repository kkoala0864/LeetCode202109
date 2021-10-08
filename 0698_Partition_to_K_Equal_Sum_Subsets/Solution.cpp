#include <Solution.h>
#include <iostream>

bool dfs(int val, int target, vector<bool>& visited, int idx, int k, vector<int>& nums) {
	if (k == 1) return true;
	if (val == target) return dfs(0, target, visited, 0, k-1, nums);

	for (int i = idx ; i < nums.size() ; ++i) {
		if (visited[i] || (nums[i] + val) > target) continue;
		visited[i] = true;
		if(dfs(nums[i] + val, target, visited, i + 1, k, nums)) return true;
		visited[i] = false;
	}
	return false;
}

bool Solution::canPartitionKSubsets(vector<int>& nums, int k)  {
	int sum = 0;
	for (const auto& iter : nums) sum += iter;

	if ((sum % k) > 0) return false;
	int average = sum / k;
	vector<bool> visited(nums.size(), false);

	return dfs(0, average, visited, 0, k, nums);
}
