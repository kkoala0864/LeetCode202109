#include <Solution.h>
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::min;

bool Solution::increasingTriplet(vector<int>& nums) {
	if (nums.size() < 3) return false;
	vector<int> record;
	for (int i = 0 ; i < nums.size() ; ++i) {
		bool find = false;
		for (int j = 0 ; j < min((int) record.size(), 3) ; ++j) {
			if (nums[i] <= record[j]) {
				record[j] = nums[i];
				find = true;
				break;
			}
		}
		if (!find && record.size() < 3) {
			record.emplace_back(nums[i]);
			if (record.size() == 3) return true;
		}
	}
	return false;
}

