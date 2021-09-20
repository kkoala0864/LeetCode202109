#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;
using std::min;

vector<vector<int>> Solution::merge(vector<vector<int>>& intervals) {
	while (true) {
		vector<vector<int>> result;
		bool change(false);
		int i = 0;
		for (; i < intervals.size() ; ++i) {
			int j = i + 1;
			for (; j < intervals.size() ; ++j) {
				if (intervals[i][0] > intervals[j][1]) {
					result.emplace_back(intervals[j]);
					change = true;
				} else if (intervals[i][1] >= intervals[j][0]) {
					intervals[i][0] = min(intervals[i][0], intervals[j][0]);
					intervals[i][1] = max(intervals[i][1], intervals[j][1]);
					change = true;
				} else {
					break;
				}
			}
			result.emplace_back(intervals[i]);
			i = j - 1;
		}
		result.swap(intervals);
		if (!change) break;
	}
	return intervals;
}
