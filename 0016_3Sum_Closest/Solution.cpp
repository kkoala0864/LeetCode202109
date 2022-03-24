#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::min;

int Solution::threeSumClosest(vector<int>& nums, int target) {
	sort(nums.begin(), nums.end());
	int result = -1;
	int minDiff = INT_MAX;
	for (int i = 0 ; i < nums.size() - 2 ; ++i) {
		int localTarget = target - nums[i];

		int left = i + 1, right = nums.size() - 1;
		while (left < right) {
			int localSum = nums[left] + nums[right];
			if (abs(localSum - localTarget) < minDiff) {
				minDiff = abs(localSum - localTarget);
				result = nums[i] + localSum;
			}
			if (localSum < localTarget) {
				++left;
			} else if (localSum > localTarget) {
				--right;
			} else {
				return target;
			}
		}
	}
	return result;
}
