#include <Solution.h>
#include <iostream>

// sliding window collect interval which element in the range
// find the minimum distance minK and maxK to calculate counts

long long Solution::countSubarrays(vector<int>& nums, int minK, int maxK) {
	long long result = 0;
	int l = 0;
	int minIdx = -1;
	int maxIdx = -1;

	for (int i = 0 ; i < nums.size() ; ++i) {
		if (minK > nums[i] || maxK < nums[i]) {
			l = i + 1;
			minIdx = -1;
			maxIdx = -1;
		} else {
			if (nums[i] == minK) minIdx = i;
			if (nums[i] == maxK) maxIdx = i;

			if (minIdx != -1 && maxIdx != -1) {
				result += (long long)((min(minIdx, maxIdx) - l) + 1);
			}
		}
	}
	return result;
}
