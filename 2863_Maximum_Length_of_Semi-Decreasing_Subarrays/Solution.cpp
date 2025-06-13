#include <Solution.h>

// target is to find maxIdx
int Solution::maxSubarrayLength(vector<int>& nums) {
	vector<int> postMin(nums.size(), INT_MAX);
	postMin.back() = nums.back();

	for (int i = nums.size() - 2 ; i >= 0 ; --i) {
		postMin[i] = min(postMin[i+1], nums[i]);
	}

	int preMax = nums[0];
	int i = 0;
	int j = 0;
	int result = 0;
	while (i < nums.size() && j < nums.size()) {
		if (preMax > postMin[j]) {
			result = max(result, j - i + 1);
			++j;
		} else {
			++i;
			if (i < nums.size()) {
				preMax = max(preMax, nums[i]);
				if (j < i) j = i;
			}
		}
	}
	return result;
}
