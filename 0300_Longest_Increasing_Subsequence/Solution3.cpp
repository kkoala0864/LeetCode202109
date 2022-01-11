#include <Solution.h>
#include <iostream>

using std::vector;

int lowerBound(const vector<int>& list, int val) {
	int start = 0, end = list.size() - 1;
	int mid = 0;
	while (start < end) {
		mid = (start + end) / 2;
		if (list[mid] == val) return mid;
		if (list[mid] > val) {
			end = mid;
		} else {
			start = mid + 1;
		}
	}
	return start;
}

int Solution::lengthOfLIS3(vector<int>& nums) {
	if (nums.empty()) return 0;
	vector<int> list;
	list.emplace_back(nums[0]);
	for (int i = 1 ; i < nums.size() ; ++i) {
		int idx = lowerBound(list, nums[i]);
		if (nums[i] > list[idx]) list.emplace_back(nums[i]);
		else list[idx] = nums[i];
	}
	return list.size();
}
