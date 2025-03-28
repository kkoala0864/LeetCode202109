#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

bool Solution::containsNearbyAlmostDuplicate3(vector<int> &nums, int k, int t) {
	if (nums.size() < 2)
		return false;

	unordered_map<long, int> uMap;

	long base = t + 1;
	for (int i = 0; i < nums.size(); ++i) {
		long bucketIdx = (long)nums[i] / base;
		if (nums[i] < 0)
			--bucketIdx;

		if (uMap.find(bucketIdx) != uMap.end())
			return true;
		if (uMap.find(bucketIdx + 1) != uMap.end() && abs(nums[i] - uMap[bucketIdx + 1]) <= t)
			return true;
		if (uMap.find(bucketIdx - 1) != uMap.end() && abs(nums[i] - uMap[bucketIdx - 1]) <= t)
			return true;
		uMap[bucketIdx] = nums[i];

		if (uMap.size() > k) {
			long removeIdx = (long)nums[i - k] / base;
			if (nums[i - k] < 0)
				--removeIdx;
			uMap.erase(removeIdx);
		}
	}
	return false;
}
