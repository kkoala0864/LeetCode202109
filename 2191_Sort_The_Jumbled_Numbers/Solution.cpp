#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;
using std::pair;

int getVal(int v, vector<int>& m) {
	if (v == 0) return m[0];
	int ret = 0;
	int base = 1;

	while (v > 0) {
		ret += (base * m[(v % 10)]);
		v /= 10;
		base *= 10;
	}
	return ret;
}

vector<int> Solution::sortJumbled(vector<int>& mapping, vector<int>& nums) {
	vector<pair<int, int>> list;
	for (int i = 0 ; i < nums.size() ; ++i) {
		list.emplace_back(pair<int, int>(getVal(nums[i], mapping), i));
	}

	sort(list.begin(), list.end());
	vector<int> result;
	for (const auto& l : list) result.emplace_back(nums[l.second]);
	return result;
}
