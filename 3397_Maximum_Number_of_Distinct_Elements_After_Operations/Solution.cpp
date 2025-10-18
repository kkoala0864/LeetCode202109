#include <Solution.h>

int Solution::maxDistinctElements(vector<int> &nums, int k) {
	sort(nums.begin(), nums.end());

	int cnt = 1;
	int cur = nums[0] - k + 1;

	for (int i = 1 ; i < nums.size() ; ++i) {
		int left = nums[i] - k;
		int right = nums[i] + k;
		if (cur <= right) {
			cur = max(left, cur) + 1;
			++cnt;
		}
	}

	return cnt;
}
