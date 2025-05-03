#include <Solution.h>

// 4 7 9 10 , k = 3
int Solution::missingElement(vector<int>& nums, int k) {
	int l = nums[0], r = nums.back() + k;

	int mid = 0;

	while (l < r) {
		mid = l + ((r - l) >> 1);

		int idx = upper_bound(nums.begin(), nums.end(), mid) - nums.begin();
		--idx;
		int total = mid - nums[0] + 1;
		int leak = total - idx - 1;
		if (leak < k) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	return l;

}
