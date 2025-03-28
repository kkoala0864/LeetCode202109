#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::cout;
using std::endl;
using std::unordered_map;

vector<int> Solution::twoSum(vector<int> &nums, int target) {
	// assume nums number bigger than 2
	unordered_map<int, int> indices_map;

	for (int i = 0; i < nums.size(); ++i) {
		if (indices_map.find(target - nums[i]) != indices_map.end()) {
			return {i, indices_map[target - nums[i]]};
		} else {
			indices_map[nums[i]] = i;
		}
	}
	return {0, 0};
}
