#include <Solution.h>

bool dfs(vector<int>& nums, int idx, int k, int sum) {
	if (k == 0 && sum == 0) return true;
	if (k == 0 || sum == 0) return false;
	if (idx == nums.size()) return false;

	// take current idx
	if (dfs(nums, idx + 1, k - 1, sum - nums[idx])) return true;

	// don't take current idx
	int i = idx;
	while (i < nums.size() && (nums[i] == nums[idx])) ++i;
	if (dfs(nums, i, k, sum)) return true;

	return false;
}

bool Solution::splitArraySameAverage(vector<int>& nums) {
	int sum = accumulate(nums.begin(), nums.end(), 0);
	int size = nums.size();
	if (sum == 0 && size > 1) return true;

	sort(nums.begin(), nums.end());

	for (int k = 1 ; k < size ; ++k) {
		if ((sum * k) % size) continue;
		int target = sum * k / size;
		if (dfs(nums, 0, k, target)) return true;
	}
	return false;
}
