#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

int Solution::findMaxConsecutiveOnes(vector<int>& nums) {
	int l = 0;
	int result = 0;

	int zCnt = 1;

	for (int i = 0 ; i < nums.size() ; ++i) {
		if (nums[i] == 0) --zCnt;
		while (l < i && zCnt < 0) {
			if (nums[l] == 0) ++zCnt;
			++l;
		}
		result = max(result, i - l + 1);
	}
	return result;
}
