#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using std::max;
using std::unordered_map;

int Solution::maxFrequencyElements(vector<int>& nums) {
	unordered_map<int, int> m;
	int maxF = 0;

	for (const auto& v : nums) {
		++m[v];
		maxF = max(maxF, m[v]);
	}

	int result = 0;
	for (const auto& v : m) {
		if (v.second == maxF) ++result;
	}

	return result * maxF;
}
