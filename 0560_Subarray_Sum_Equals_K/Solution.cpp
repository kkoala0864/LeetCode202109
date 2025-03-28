#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

int Solution::subarraySum(vector<int> &nums, int k) {
	unordered_map<int, int> uMap;
	int sum = 0;
	int result = 0;

	for (int i = 0; i < nums.size(); ++i) {
		sum += nums[i];
		if (sum == k)
			++result;
		if (uMap.find(sum - k) != uMap.end())
			result += uMap[sum - k];
		++uMap[sum];
	}
	return result;
}
