#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

int Solution::minSwaps(vector<int>& nums) {
	int ones = 0;
	int oneCnt = 0;
	int maxOneCnt = 0;
	int n = nums.size();
	for (const auto& iter : nums) if (iter == 1) ++ones;

	vector<int> nums2(n * 2, 0);
	for (int i = 0 ; i < n * 2 ; ++i) nums2[i] = nums[i%n];

	for (int i = 0 ; i < n * 2 ; ++i) {
		if (i >= ones && nums2[i-ones] == 1) --oneCnt;
		if (nums2[i] == 1) ++oneCnt;
		maxOneCnt = max(maxOneCnt, oneCnt);
	}
	return ones - maxOneCnt;
}
