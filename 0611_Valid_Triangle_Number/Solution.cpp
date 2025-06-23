#include <Solution.h>

int Solution::triangleNumber(vector<int>& nums) {
	sort(nums.begin(), nums.end());

	int result = 0;
	int size = nums.size();
	for (int i = 0 ; i < (size - 2); ++i) {
		for (int j = i + 1 ; j < size ; ++j) {
			int start = j + 1;
			int idx = lower_bound(nums.begin() + start, nums.end(), nums[i] + nums[j]) - nums.begin();
			if (idx == (start)) continue;
			result += (idx - start);
		}
	}
	return result;
}
