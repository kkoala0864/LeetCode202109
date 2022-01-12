#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <map>

using std::sort;
using std::map;

/*
bool Solution::canAttendMeetings(vector<vector<int>>& intervals) {
	if (intervals.empty()) return true;
	auto cmp = [] (const vector<int>& lhs, const vector<int>& rhs) { return lhs[0] < rhs[0]; };
	sort(intervals.begin(), intervals.end(), cmp);
	for (int i = 1 ; i < intervals.size() ; ++i) if (intervals[i][0] < intervals[i-1][1]) return false;
	return true;
}
*/
bool Solution::canAttendMeetings(vector<vector<int>>& intervals) {
	map<int, int> sMap;
	for (const auto& interval : intervals) {
		sMap[interval[0]] += 1;
		sMap[interval[1]] += -1;
	}

	int cnt = 0;
	for (const auto iter : sMap) {
		cnt += iter.second;
		if (cnt > 1) return false;
	}
	return true;
}
