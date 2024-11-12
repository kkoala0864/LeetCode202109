#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;
using std::cout;
using std::endl;

int getBitCnt(int v) {
	int result = 0;
	while (v) {
		++result;
		v &= (v-1);
	}
	return result;
}

bool Solution::canSortArray(vector<int>& nums) {
	vector<int> cmp = nums;
	sort(nums.begin(), nums.end());
	int li = 0;
	for (int i = 1 ; i < nums.size() ; ++i) {
		if (getBitCnt(cmp[i]) == getBitCnt(cmp[i-1])) continue;
		sort(cmp.begin() + li, cmp.begin() + i);
		for (int j = li ; j < i ; ++j) {
			if (cmp[j] != nums[j]) return false;
		}
		li = i;
	}
	if (li != nums.size() - 1) {
		sort(cmp.begin() + li, cmp.end());
		for (int j = li ; j < nums.size() ; ++j) {
			if (cmp[j] != nums[j]) return false;
		}
	}
	return true;
}
