#include <Solution.h>

// subarray[i, j] => which i <= k <= j
// score = min(nums[i] ~ nums[j]) * (j - i + 1)
// get maximum score
int Solution::maximumScore(vector<int>& nums, int k) {
	int l = k, r = k;
	int size = nums.size();

	int curMin = nums[k];
	int result = curMin;

	while (l > 0 || r < size - 1) {
		int left = l == 0 ? INT_MIN : nums[l-1];
		int right = r == size - 1 ? INT_MIN : nums[r + 1];
		if (left > right) {
			--l;
		} else {
			++r;
		}
		curMin = min({curMin, nums[l], nums[r]});
		result = max(result, curMin*(r - l + 1));
	}
	return result;
}
