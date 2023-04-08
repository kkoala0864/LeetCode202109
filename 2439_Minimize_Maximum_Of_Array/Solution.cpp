#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;
using std::cout;
using std::endl;

int Solution::minimizeArrayValue(vector<int>& nums) {
	long long minVal = 0;
	long long sum = 0;
	int result = 0;
	long long offset = 0;

	for (const auto& v : nums) sum += v;
	for (int i = nums.size() - 1 ; i > 0 ; --i) {
		minVal = sum / (i + 1);
		if (sum % (i+1)) minVal += 1;
		if ((nums[i] + offset) > minVal) {
			offset += (nums[i] - minVal);
			nums[i] = minVal;
		} else {
			nums[i] += offset;
			offset = 0;
		}
		result = max(result, nums[i]);
		sum -= nums[i];
	}
	nums[0] += offset;
	result = max(result, nums[0]);
	return result;
}
