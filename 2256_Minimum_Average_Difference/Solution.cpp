#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::min;

int Solution::minimumAverageDifference(vector<int>& nums) {
	int result = INT_MAX;
	int minAverage = INT_MAX;
	long preSum = 0;
	int average = 0;
	long tailSum = 0;
	int size = nums.size();

	for (int i = 0 ; i < size ; ++i) tailSum += nums[i];
	for (int i = 0 ; i < size ; ++i) {
		preSum += nums[i];
		tailSum -= nums[i];
		average = abs(preSum / (i + 1) - (tailSum == 0 ? 0 : (tailSum / (size - i - 1))));
		if (average < minAverage) {
			minAverage = average;
			result = i;
		}
	}
	return result;
}
