#include <Solution.h>
#include <iostream>

using std::vector;

int lower_bound(vector<int>& result, int num) {
	int start = 0;
	int end = result.size();
	int mid = 0;
	while (start < end) {
		mid = (start + end) / 2;
		if (result[mid] > num) {
			end = mid;
		} else if (result[mid] < num) {
			start = mid + 1;
		} else {
			return mid;
		}
	}
	return start;
}

int Solution::lengthOfLIS2(vector<int>& nums) {
	if (nums.empty()) return 0;
	vector<int> result(1, nums[0]);
	for (int i = 1 ; i < nums.size() ; ++i) {
		int idx = lower_bound(result, nums[i]);
		if (idx == result.size()) result.emplace_back(nums[i]);
		else result[idx] = nums[i];
	}
	return result.size();
}
