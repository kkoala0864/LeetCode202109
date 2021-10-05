#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;

bool Solution::canAttendMeetings(vector<vector<int>>& intervals) {
	if (intervals.empty()) return true;
	auto cmp = [] (const vector<int>& lhs, const vector<int>& rhs) { return lhs[0] < rhs[0]; };
	sort(intervals.begin(), intervals.end(), cmp);
	for (int i = 1 ; i < intervals.size() ; ++i) if (intervals[i][0] < intervals[i-1][1]) return false;
	return true;
}

