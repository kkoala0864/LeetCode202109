#include <Solution.h>

vector<int> Solution::buildArray(vector<int>& nums) {
	int size = nums.size();
	for (int i = 0 ; i < size ; ++i) {
		nums[i] += (1000 * (nums[nums[i]] % 1000));
	}
	for (int i = 0 ; i < size ; ++i) {
		nums[i] /= 1000;
	}
	return nums;
}
