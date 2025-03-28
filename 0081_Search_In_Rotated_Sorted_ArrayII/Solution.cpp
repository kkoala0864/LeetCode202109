#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;
bool Solution::search(vector<int> &nums, int target) {
	int left = 0;
	int right = nums.size() - 1;
	int mid = 0;
	while (left <= right) {
		int mid = (left + right) / 2;

		if (nums[mid] == target)
			return true;
		while (nums[left] == nums[mid] && left < mid) {
			++left;
		}
		while (nums[right] == nums[mid] && right > mid) {
			--right;
		}
		if (nums[left] <= nums[mid]) {
			if (target >= nums[left] && target <= nums[mid]) {
				right = mid - 1;
			} else {
				left = mid + 1;
			}
		} else {
			if (target >= nums[mid] && target <= nums[right]) {
				left = mid + 1;
			} else {
				right = mid - 1;
			}
		}
	}
	return false;
}
/*
bool Solution::search(vector<int>& nums, int target) {
        unordered_map<int, bool> uMap;
        for (const auto& num : nums) uMap[num] = true;
        return uMap.find(target) != uMap.end();
}
*/
