#include <Solution.h>

int Solution::longestSubarray(vector<int> &nums) {
	int l = 0;
	int result = 0;
	int zeroCnt = 0;
	for (int r = 0 ; r < nums.size() ; ++r) {
		if (nums[r] == 0) ++zeroCnt;
		while (l <= r && zeroCnt > 1) {
			if (nums[l] == 0) --zeroCnt;
			++l;
		}
		result = max(result, r - l);
	}
	return result;
}
