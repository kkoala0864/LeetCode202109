#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

int Solution::subarraySum2(vector<int> &nums, int k) {
	unordered_map<int, int> map;
	int sum = 0;
	int result = 0;
	for (int i = 0; i < nums.size(); ++i) {
		sum += nums[i];
		if (sum == k)
			++result;
		if (map.find(sum - k) != map.end()) {
			result += map[sum - k];
		}
		++map[sum];
	}
	return result;
}
