#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

int Solution::majorityElement(vector<int>& nums) {
	int maxIdx = nums[0];
	unordered_map<int, int> map;
	for (const auto& iter : nums) {
		++map[iter];
		if (map[iter] > map[maxIdx]) {
			maxIdx = iter;
		}
	}
	return maxIdx;
}
