#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using std::unordered_map;
using std::max;

int Solution::getLargestOutlier(vector<int>& nums) {
	unordered_map<int, int> m;
	int total = 0;
	for (const auto& v : nums) {
		++m[v];
		total += v;
	}

	int result = INT_MIN;
	for (auto& e : m) {
		total -= e.first;
		--e.second;
		int rest = total - e.first;
		if (m.count(rest) && m[rest] > 0) {
			result = max(result, rest);
		}
		++e.second;
		total += e.first;
	}
	return result;
}
