#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;

int Solution::eraseOverlapIntervals2(vector<vector<int>> &intervals) {
	sort(intervals.begin(), intervals.end());
	int cnt = 0;
	int prev = 0;
	for (int i = 1; i < intervals.size(); ++i) {
		if (intervals[i][0] >= intervals[prev][1]) {
			prev = i;
		} else {
			++cnt;
			if (intervals[i][1] < intervals[prev][1])
				prev = i;
		}
	}
	return cnt;
}
