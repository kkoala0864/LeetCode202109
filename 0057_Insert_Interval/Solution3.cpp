#include <Solution.h>
#include <iostream>

using std::min;
using std::max;

vector<vector<int>> Solution::insert3(vector<vector<int>>& intervals, vector<int>& newInterval) {
	vector<vector<int>> result;
	int idx = 0;
	while (idx < intervals.size() && intervals[idx][1] < newInterval[0]) {
		result.emplace_back(intervals[idx++]);
	}

	while (idx < intervals.size() && intervals[idx][0] <= newInterval[1]) {
		newInterval[0] = min(intervals[idx][0], newInterval[0]);
		newInterval[1] = max(intervals[idx][1], newInterval[1]);
		++idx;
	}

	result.emplace_back(newInterval);
	while (idx < intervals.size()) {
		result.emplace_back(intervals[idx++]);
	}
	return result;
}
