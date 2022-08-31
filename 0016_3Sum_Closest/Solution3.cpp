#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::sort;
using std::min;

int Solution::threeSumClosest3(vector<int>& nums, int target) {
	sort(nums.begin(), nums.end());
	int sum = 0;
	int diff = INT_MAX;
	int result = 0;
	for (int i = 0 ; i < nums.size() ; ++i) {
		int start = i + 1, end = nums.size() - 1;
		while (start < end) {
			int curSum = nums[i] + nums[start] + nums[end];
			if (diff > abs(curSum - target)) {
				diff = abs(curSum - target);
				result = curSum;
			}

			if (curSum == target) return target;
			else if (curSum > target) --end;
			else ++start;
		}
	}
	return result;
}

