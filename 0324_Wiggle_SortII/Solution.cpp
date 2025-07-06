#include <Solution.h>

void Solution::wiggleSort(vector<int> &nums) {
	sort(nums.begin(), nums.end());

	vector<int> result = nums;
	int ni = nums.size() - 1;
	for (int i = 1 ; i < nums.size() ; i += 2) {
		result[i] = nums[ni--];
	}
	for (int i = 0 ; i < nums.size() ; i += 2) {
		result[i] = nums[ni--];
	}
	nums = std::move(result);
}

