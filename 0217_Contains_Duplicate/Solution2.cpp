#include <Solution.h>
#include <iostream>
#include <unordered_set>

using std::unordered_set;

bool Solution::containsDuplicate2(vector<int> &nums) {
	unordered_set<int> set;
	for (const auto &iter : nums) {
		if (set.find(iter) != set.end())
			return true;
		set.emplace(iter);
	}
	return false;
}
