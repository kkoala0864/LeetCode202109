#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;
using std::max;

int Solution::maxDistinctElements(vector<int>& nums, int k) {
	sort(nums.begin(), nums.end());

	int cnt = 1;
	int last = nums[0] - k;
	for (int i = 1 ; i < nums.size() ; ++i) {
		int expectMin = last + 1;
		int diff = expectMin - nums[i];
		if (diff <= k) {
			++cnt;
			last = max(expectMin, nums[i] - k);
		}
	}
	return cnt;
}
