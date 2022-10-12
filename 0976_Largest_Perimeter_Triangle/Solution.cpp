#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;

// how long is this list ?
// what's the range of value in this list?
// does it contain negative value ?

// 0, 1, 2, 3, 4
int Solution::largestPerimeter(vector<int>& nums) {
	sort(nums.begin(), nums.end(), std::greater<int>());

	for (int i = 0 ; i < nums.size() - 2 ; ++i) {
		if (nums[i] < (nums[i+1] + nums[i+2])) return (nums[i] + nums[i+1] + nums[i+2]);
	}
	return 0;
}
