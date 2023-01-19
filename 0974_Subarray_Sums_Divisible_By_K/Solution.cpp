#include <Solution.h>
#include <iostream>

int Solution::subarraysDivByK(vector<int>& nums, int k) {
	vector<int> mod(k, 0);

	mod[0] = 1;
	int result = 0;
	int curSum = 0;
	for (int i = 0 ; i < nums.size() ; ++i) {
		curSum += nums[i];
		while (curSum < 0) {
			curSum += k;
		}
		result += mod[curSum % k];
		++mod[curSum % k];
	}
	return result;
}
