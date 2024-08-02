#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::min;

int Solution::minSwaps(vector<int>& nums) {
	int totalOne = 0;
	for (const auto& v : nums) {
		if (v == 1) ++totalOne;
	}

	int oneCnt = 0;
	int result = INT_MAX;
	int size = nums.size();
	for (int i = 0 ; i < size * 2 ; ++i) {
		int oi = i % size;
		if (nums[oi] == 1) ++oneCnt;

		if (i >= totalOne) {
			int lastIdx = (i - totalOne) % size;
			if (nums[lastIdx] == 1) --oneCnt;
		}
		if (i >= (totalOne - 1)) {
			result = min(result, totalOne - oneCnt);
		}
	}
	return result;
}
