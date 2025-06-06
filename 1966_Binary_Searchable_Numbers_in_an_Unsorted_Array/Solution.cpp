#include <Solution.h>

int Solution::binarySearchableNumbers(vector<int>& nums) {
	vector<int> preMax(nums.size(), 0);
	vector<int> postMin(nums.size(), 0);

	int cur = INT_MIN;
	for (int i = 0 ; i < nums.size() ; ++i) {
		preMax[i] = cur;
		cur = max(cur, nums[i]);
	}
	cur = INT_MAX;
	for (int i = nums.size() - 1 ; i >= 0 ; --i) {
		postMin[i] = cur;
		cur = min(cur, nums[i]);
	}
	int result = 0;
	for (int i = 0 ; i < nums.size() ; ++i) {
		if (preMax[i] < nums[i] && postMin[i] > nums[i]) {
			++result;
		}
	}
	return result;

}
