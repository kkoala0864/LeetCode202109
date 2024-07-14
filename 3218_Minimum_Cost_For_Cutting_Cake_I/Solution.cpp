#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;

int Solution::minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
	sort(horizontalCut.begin(), horizontalCut.end(), std::greater<int>());
	sort(verticalCut.begin(), verticalCut.end(), std::greater<int>());
	int hi = 0, vi = 0;

	int result = 0;
	while (hi < horizontalCut.size() && vi < verticalCut.size()) {
		if (horizontalCut[hi] > verticalCut[vi]) {
			result += (horizontalCut[hi] * (vi + 1));
			++hi;
		} else {
			result += (verticalCut[vi] * (hi + 1));
			++vi;
		}
	}

	while (hi < horizontalCut.size()) {
		result += (horizontalCut[hi++] * (vi + 1));
	}
	while (vi < verticalCut.size()) {
		result += (verticalCut[vi++] * (hi + 1));
	}
	return result;
}
