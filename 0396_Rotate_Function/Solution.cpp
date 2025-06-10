#include <Solution.h>

int Solution::maxRotateFunction(vector<int>& nums) {
	int baseSum = 0;
	int fSum = 0;
	int size = nums.size();
	for (int i = 0 ; i < nums.size() ; ++i) {
		baseSum += nums[i];
		fSum += (i * nums[i]);
	}
	int result = fSum;
	for (int i = nums.size() - 1 ; i > 0 ; --i) {
		fSum -= (size * nums[i]);
		fSum += baseSum;
		result = max(result, fSum);
	}
	return result;
}
