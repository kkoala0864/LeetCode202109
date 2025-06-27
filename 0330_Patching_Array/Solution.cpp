#include <Solution.h>

int Solution::minPatches(vector<int>& nums, int n) {
	long long far = 1;
	int ni = 0;
	int result = 0;
	while (far <= n) {
		if (ni < nums.size() && nums[ni] <= far) {
			far += nums[ni++];
		} else {
			++result;
			far <<= 1;
		}
	}
	return result;
}
