#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

bool Solution::containsNearbyAlmostDuplicate2(vector<int> &nums, int k, int t) {
	if (nums.size() < 0 || k < 0 || t < 0)
		return false;

	unordered_map<long long, long long> uMap;
	long long base = (long long)t + 1;

	for (int i = 0; i < nums.size(); ++i) {
		int idx = nums[i] / base;
		if (nums[i] < 0)
			--idx;

		if (uMap.find(idx) != uMap.end())
			return true;
		uMap[idx] = nums[i];
		if (uMap.find(idx + 1) != uMap.end() && abs(uMap[idx + 1] - nums[i]) <= t)
			return true;
		if (uMap.find(idx - 1) != uMap.end() && abs(uMap[idx - 1] - nums[i]) <= t)
			return true;
		if (uMap.size() > k) {
			int removeIdx = nums[i - k] / base;
			if (nums[i - k] < 0)
				--removeIdx;
			uMap.erase(removeIdx);
		}
	}
	return false;
}
