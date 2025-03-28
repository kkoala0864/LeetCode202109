#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::max;

int Solution::numberOfArithmeticSlices2(vector<int> &nums) {
	if (nums.size() < 3)
		return 0;

	int result = 0;
	for (int i = 2; i < nums.size(); ++i) {
		int cnt = 0;
		while (i < nums.size() && ((nums[i] - nums[i - 1]) == (nums[i - 1] - nums[i - 2]))) {
			++cnt;
			result += cnt;
			++i;
		}
	}
	return result;
}
