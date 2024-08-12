#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

int Solution::tupleSameProduct(vector<int>& nums) {
	unordered_map<int, int> m;

	for (int i = 0 ; i < nums.size() ; ++i) {
		for (int j = i + 1 ; j < nums.size() ; ++j) {
			++m[nums[i] * nums[j]];
		}
	}

	int result = 0;
	for (const auto& e : m) {
		if (e.second == 1) continue;
		int v = (e.second * (e.second - 1)) * 4;
		result += v;
	}
	return result;
}
