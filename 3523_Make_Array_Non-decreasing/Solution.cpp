#include <Solution.h>
#include <iostream>

int Solution::maximumPossibleSize(vector<int>& nums) {

	vector<int> l;
	for (const auto& v : nums) {
		if (l.empty() || l.back() <= v) l.emplace_back(v);
	}
	return l.size();
}
