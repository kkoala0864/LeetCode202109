#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::min;
using std::max;

vector<vector<int>> Solution::removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
	vector<vector<int>> result;
	int idx = 0;
	while (idx < intervals.size() && intervals[idx][1] <= toBeRemoved[0]) result.emplace_back(intervals[idx++]);

	while (idx < intervals.size() && toBeRemoved[0] <= intervals[idx][1]) {
		if (intervals[idx][0] < toBeRemoved[0]) {
			result.push_back({intervals[idx][0], min(intervals[idx][1], toBeRemoved[0])});
		}
		if (intervals[idx][1] > toBeRemoved[1]) {
			result.push_back({max(intervals[idx][0], toBeRemoved[1]), intervals[idx][1]});
		}
		++idx;
	}

	while (idx < intervals.size()) result.emplace_back(intervals[idx++]);
	return result;
}
