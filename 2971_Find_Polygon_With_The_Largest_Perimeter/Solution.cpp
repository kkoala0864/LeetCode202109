#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;
using std::max;

long long Solution::largestPerimeter(vector<int>& nums) {
	sort(nums.begin(), nums.end());

	long long result = 0;
	long long sum = nums[0] + nums[1];

	for (int i = 2 ; i < nums.size() ; ++i) {
		if (nums[i] < sum) {
			result = max(result, sum + nums[i]);
		}
		sum += nums[i];
	}

	return result == 0 ? -1 : result;
}
