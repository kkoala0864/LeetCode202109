#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

/*
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
*/

int Solution::majorityElement(vector<int>& nums) {
	int i = 0;
	int m = 0;
	int iter = 0;
	while (iter < nums.size()) {
		if (i == 0) {
			m = nums[iter];
			i = 1;
		} else {
			if (m == nums[iter]) {
				++i;
			} else {
				--i;
			}
		}
		++iter;
	}
	return m;
}
