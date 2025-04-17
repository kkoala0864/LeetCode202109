#include <Solution.h>
#include <iostream>
#include <unordered_map>

int Solution::countPairs(vector<int>& nums, int k) {
	unordered_map<int, vector<int>> idx;

	int result = 0;
	for (int i = 0 ; i < nums.size() ; ++i) {
		for (const auto& v : idx[nums[i]]) {
			if (((v * i) % k) == 0) ++result;
		}
		idx[nums[i]].emplace_back(i);
	}
	return result;
}
