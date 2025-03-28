#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

bool Solution::containsDuplicate(vector<int> &nums) {
	unordered_map<int, bool> uMap;
	for (const auto &iter : nums) {
		if (uMap.find(iter) != uMap.end())
			return true;
		uMap[iter] = true;
	}
	return false;
}
