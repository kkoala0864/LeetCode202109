#include <Solution.h>
#include <iostream>
#include <climits>

using std::cout;
using std::endl;
using std::min;

int Solution::minSubArrayLen(int target, vector<int> &nums) {
	int left = -1, right = 0;
	int size = nums.size();
	int result = INT_MAX;

	int product = 0;
	while (left < size && right < size) {
		while (right < size) {
			product += nums[right];
			if (product >= target) {
				result = min(result, right - left);
				++right;
				break;
			}
			++right;
		}

		while (left < right) {
			++left;
			product -= nums[left];
			if (product >= target) {
				result = min(result, right - left - 1);
			} else {
				break;
			}
		}
	}
	return result == INT_MAX ? 0 : result;
}
