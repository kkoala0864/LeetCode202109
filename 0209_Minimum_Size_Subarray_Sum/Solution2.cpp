#include <Solution.h>
#include <iostream>
#include <climits>

using std::min;

int Solution::minSubArrayLen2(int target, vector<int>& nums) {
	int sum = 0;
	int start = 0, iter = 0;
	int result = INT_MAX;
	while (iter < nums.size()) {
		sum += nums[iter];
		while (sum >= target) {
			result = min(result, iter - start + 1);
			sum -= nums[start];
			++start;
		}
		++iter;
	}
	return result == INT_MAX ? 0 : result;
}
