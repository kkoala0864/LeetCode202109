#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::min;

int Solution::minStartValue(vector<int>& nums) {
	int minVal = INT_MAX;
	int cnt = 0;
	for (int i = 0 ; i < nums.size() ; ++i) {
		cnt += nums[i];
		minVal = min(minVal, cnt);
	}
	int result = minVal >= 0 ? 1 : -minVal + 1;
	return result;
}
