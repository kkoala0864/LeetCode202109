#include <Solution.h>

int Solution::triangleNumber(vector<int>& nums) {
	sort(nums.begin(), nums.end());

	int result = 0;
	for (int r = 0 ; r < nums.size() ; ++r) {
		int l = 0, mid = r - 1;
		while (l < mid) {
			int v = nums[l] + nums[mid];

			if (v <= nums[r]) {
				++l;
			} else {
				result += (mid - l);
				--mid;
			}
		}
	}
	return result;
}
