#include <Solution.h>
#include <iostream>

int Solution::missingNumber2(vector<int>& nums) {
	int sum = 0;
	for (const auto& iter : nums) sum += iter;
	int n = nums.size();
	int total = (n * (n+1)) / 2;
	return total - sum;
}
