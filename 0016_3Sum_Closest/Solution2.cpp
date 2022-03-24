#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::sort;

int Solution::threeSumClosest2(vector<int>& nums, int target) {
	sort(nums.begin(), nums.end());
	int minDiff = INT_MAX;
	int result = 0;
	for (int i = 0 ; i < nums.size() - 2 ; ++i) {
		int start = i + 1, end = nums.size() - 1;
		while (start < end) {
			int local = nums[i] + nums[start] + nums[end];
			if (minDiff > abs(local - target)) {
				minDiff = min(minDiff, abs(local-target));
				result = local;
			}
			if (local > target) --end;
			else if (local == target) return local;
			else ++start;
		}
	}
	return result;
}

