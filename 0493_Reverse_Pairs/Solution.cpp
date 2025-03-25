#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;
using std::inplace_merge;

void dfs(vector<int>& nums, int l, int r, int& result) {
	if (l == r-1) return;

	int mid = l + ((r-l-1) >> 1);
	dfs(nums, l, mid + 1, result);
	dfs(nums, mid + 1, r, result);

	for (int j = mid + 1 ; j < r ; ++j) {
		int idx = upper_bound(nums.begin() + l, nums.begin() + mid + 1, (long long)2 * nums[j]) - nums.begin();
		result += (mid - idx + 1);
	}

	inplace_merge(nums.begin() + l, nums.begin() + mid + 1, nums.begin() + r);
}

int Solution::reversePairs(vector<int>& nums) {
	int size = nums.size();
	int result = 0;
	dfs(nums, 0, size, result);
	return result;
}
