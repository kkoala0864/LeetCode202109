#include <Solution.h>
#include <iostream>

long long Solution::countSubarrays(vector<int>& nums, long long k) {
	int l = 0;
	long long sum = 0;
	long long result = 0;
	for (int i = 0 ; i < nums.size() ; ++i) {
		sum += nums[i];

		while (l <= i && ((long long)(sum * (long long)(i - l + 1))) >= k) {
			sum -= nums[l++];
		}

		result += (i - l + 1);
	}
	return result;
}
