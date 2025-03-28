#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;

int Solution::eraseOverlapIntervals(vector<vector<int>> &intervals) {
	auto cmp = [](const vector<int> &lhs, const vector<int> &rhs) { return lhs[0] < rhs[0]; };

	sort(intervals.begin(), intervals.end(), cmp);

	int result(0);
	for (int i = 1, prev = 0; i < intervals.size(); ++i) {
		if (intervals[i][0] < intervals[prev][1]) {
			++result;
			if (intervals[i][1] < intervals[prev][1])
				prev = i;
		} else {
			prev = i;
		}
	}
	return result;
}
