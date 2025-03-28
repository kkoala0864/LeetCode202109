#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

vector<int> Solution::twoSum2(vector<int> &nums, int target) {
	unordered_map<int, int> record;
	for (int i = 0; i < nums.size(); ++i) {
		if (record.find(target - nums[i]) != record.end()) {
			return {i, record[target - nums[i]]};
		} else {
			record[nums[i]] = i;
		}
	}
	return {0, 0};
}
