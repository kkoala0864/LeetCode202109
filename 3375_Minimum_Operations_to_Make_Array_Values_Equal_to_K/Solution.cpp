#include <Solution.h>
#include <iostream>
#include <set>

int Solution::minOperations(vector<int>& nums, int k) {
	set<int> s;
	for (const auto& v : nums) s.emplace(v);

	int result = 0;

	for (const auto& v : s) {
		if (v < k) return -1;
		if (v > k) ++result;
	}

	return result;
}
