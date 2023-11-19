#include <Solution.h>
#include <iostream>
#include <map>

using std::map;

int Solution::reductionOperations(vector<int>& nums) {
	map<int, int, std::greater<int>> m;
	for (const auto& v : nums) ++m[v];

	int result = 0;
	int pre = 0;

	auto iter = m.begin();
	while (iter != m.end()) {
		pre += iter->second;
		++iter;
		if (iter != m.end()) {
			result += pre;
		}
	}
	return result;
}
