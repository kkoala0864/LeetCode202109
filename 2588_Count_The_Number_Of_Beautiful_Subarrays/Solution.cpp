#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

long long Solution::beautifulSubarrays(vector<int> &nums) {
	long long result = 0;
	unordered_map<unsigned int, long long> uMap;
	uMap[0] = 1;
	unsigned int val = 0;

	for (int i = 0; i < nums.size(); ++i) {
		val ^= nums[i];
		if (uMap.count(val)) {
			result += uMap[val];
		}
		++uMap[val];
	}
	return result;
}
