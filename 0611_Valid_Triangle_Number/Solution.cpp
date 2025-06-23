#include <Solution.h>

int Solution::triangleNumber(vector<int>& nums) {
	sort(nums.begin(), nums.end());

	int result = 0;
	int size = nums.size();
	for (int r = size - 1 ; r >= 2 ; --r) {
		int l = 0;
		int mid = r - 1;
		while (l < mid) {
			if ((nums[l] + nums[mid]) > nums[r]) {
				result += (mid - l);
				--mid;
			} else {
				++l;
			}
		}
	}
	return result;
}
