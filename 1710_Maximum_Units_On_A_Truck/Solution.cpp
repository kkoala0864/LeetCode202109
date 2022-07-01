#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;
using std::min;

int Solution::maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
	auto cmp = [](vector<int>&lhs, vector<int>& rhs) { return lhs[1] == rhs[1] ? lhs[0] < rhs[0] : lhs[1] > rhs[1]; };
	sort(boxTypes.begin(), boxTypes.end(), cmp);
	int result = 0;
	for (const auto& ele : boxTypes) {
		int unit = min(ele[0], truckSize);
		result += (unit * ele[1]);
		truckSize -= unit;
		if (truckSize == 0) break;
	}
	return result;
}
