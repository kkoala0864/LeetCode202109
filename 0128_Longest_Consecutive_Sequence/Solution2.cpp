#include <Solution.h>
#include <iostream>
#include <unordered_set>
#include <algorithm>

using std::unordered_set;
using std::max;

int Solution::longestConsecutive2(vector<int>& nums) {
	unordered_set<int> set;
	for (const auto& iter : nums) set.emplace(iter);

	int result = 0;
	for (const auto& iter : set) {
		if (set.find(iter-1) == set.end()) {
			int num = iter;
			while (set.find(num) != set.end()) ++num;
			result = max(result, num - iter);
		}
	}
	return result;
}
