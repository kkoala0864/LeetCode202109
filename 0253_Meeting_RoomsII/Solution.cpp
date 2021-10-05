#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;

int Solution::minMeetingRooms(vector<vector<int>>& intervals) {
	auto cmp = [](const vector<int>& lhs, const vector<int>& rhs) { return lhs[0] < rhs[0]; };
	sort(intervals.begin(), intervals.end(), cmp);

	vector<vector<vector<int>>> rooms;
	rooms.emplace_back(vector<vector<int>>(1, intervals[0]));

	for (int i = 1 ; i < intervals.size() ; ++i) {
		int j = 0;
		for (; j < rooms.size() ; ++j) {
			if (intervals[i][0] >= rooms[j].back()[1]) {
				rooms[j].emplace_back(intervals[i]);
				break;
			}
		}
		if (j == rooms.size())
			rooms.emplace_back(vector<vector<int>>(1, intervals[i]));
	}
	return rooms.size();
}
