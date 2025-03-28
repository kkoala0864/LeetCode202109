#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

bool Solution::containsNearbyDuplicate2(vector<int> &nums, int k) {
	unordered_map<int, int> uMap;
	for (int i = 0; i < nums.size(); ++i) {
		if (uMap.find(nums[i]) != uMap.end()) {
			if (abs(uMap[nums[i]] - i) <= k)
				return true;
		}
		uMap[nums[i]] = i;
	}
	return false;
}
