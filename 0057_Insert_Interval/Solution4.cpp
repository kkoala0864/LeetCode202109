#include <Solution.h>
#include <iostream>

using std::max;
using std::min;

vector<vector<int>> Solution::insert4(vector<vector<int>> &intervals, vector<int> &newInterval) {
	vector<vector<int>> result;
	int i = 0;
	while (i < intervals.size() && newInterval[0] > intervals[i][1]) {
		result.emplace_back(intervals[i++]);
	}
	while (i < intervals.size() && newInterval[1] >= intervals[i][0]) {
		newInterval[0] = min(newInterval[0], intervals[i][0]);
		newInterval[1] = max(newInterval[1], intervals[i][1]);
		++i;
	}
	result.emplace_back(newInterval);
	while (i < intervals.size())
		result.emplace_back(intervals[i++]);
	return result;
}
