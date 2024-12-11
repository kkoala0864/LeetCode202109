#include <Solution.h>
#include <iostream>
#include <map>
#include <algorithm>

using std::map;
using std::max;

int Solution::maximumBeauty(vector<int>& nums, int k) {
	map<int, int> m;
	for (const auto& v : nums) {
		++m[v-k];
		--m[v+k+1];
	}
	int cur = 0;
	int result = 0;
	for (const auto& e : m) {
		cur += e.second;
		result = max(result, cur);
	}
	return result;
}
