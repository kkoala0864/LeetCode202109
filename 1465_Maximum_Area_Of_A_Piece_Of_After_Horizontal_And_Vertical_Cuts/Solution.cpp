#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;
using std::sort;

int Solution::maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts) {
	sort(horizontalCuts.begin(), horizontalCuts.end());
	sort(verticalCuts.begin(), verticalCuts.end());
	horizontalCuts.emplace_back(h);
	verticalCuts.emplace_back(w);
	long hMax = horizontalCuts[0], wMax = verticalCuts[0], mod = 1e9 + 7;
	for (int i = 1; i < horizontalCuts.size(); ++i) {
		hMax = max(hMax, (long)horizontalCuts[i] - (long)horizontalCuts[i - 1]);
	}
	for (int j = 1; j < verticalCuts.size(); ++j) {
		wMax = max(wMax, (long)verticalCuts[j] - (long)verticalCuts[j - 1]);
	}
	long result = (hMax * wMax) % mod;
	return result;
}
