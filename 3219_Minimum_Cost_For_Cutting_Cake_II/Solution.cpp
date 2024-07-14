#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;

long long Solution::minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
	sort(horizontalCut.begin(), horizontalCut.end(), std::greater<int>());
	sort(verticalCut.begin(), verticalCut.end(), std::greater<int>());

	long long result = 0;
	int vi = 0, hi = 0;
	while (vi < verticalCut.size() && hi < horizontalCut.size()) {
		if (verticalCut[vi] > horizontalCut[hi]) {
			result += ((long long) verticalCut[vi] * (long long)(hi + 1));
			++vi;
		} else {
			result += ((long long) horizontalCut[hi] * (long long)(vi + 1));
			++hi;
		}
	}

	while (vi < verticalCut.size()) {
		result += ((long long) verticalCut[vi] * (long long)(hi + 1));
		++vi;
	}
	while (hi < horizontalCut.size()) {
		result += ((long long) horizontalCut[hi] * (long long)(vi + 1));
		++hi;
	}
	return result;
}
