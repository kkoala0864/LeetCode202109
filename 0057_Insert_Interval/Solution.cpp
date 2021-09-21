#include <Solution.h>
#include <iostream>

using std::min;
using std::max;
using std::cout;
using std::endl;

vector<vector<int>> Solution::insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
	vector<vector<int>> result;

	int idx = 0;
	int size = intervals.size();

	while (idx < size && intervals[idx][1] < newInterval[0]) {
		result.emplace_back(intervals[idx++]);
	}

	while (idx < size && intervals[idx][0] <= newInterval[1]) {
		newInterval[0] = min(intervals[idx][0], newInterval[0]);
		newInterval[1] = max(intervals[idx][1], newInterval[1]);
		++idx;
	}
	result.emplace_back(newInterval);

	while (idx < size) {
		result.emplace_back(intervals[idx++]);
	}

	return result;
}
