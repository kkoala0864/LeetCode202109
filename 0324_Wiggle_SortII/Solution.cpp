#include <Solution.h>
#include <iostream>

// 1, 1, 1, 4, 5, 6, 7
void Solution::wiggleSort(vector<int>& nums) {
	sort(nums.begin(), nums.end());

	vector<int> result = nums;
	int rIdx = 1;
	int nIdx = nums.size() - 1;

	while (rIdx < result.size()) {
		result[rIdx] = nums[nIdx--];
		rIdx += 2;
	}
	rIdx = 0;
	while (rIdx < result.size()) {
		result[rIdx] = nums[nIdx--];
		rIdx += 2;
	}
	nums = move(result);
}
