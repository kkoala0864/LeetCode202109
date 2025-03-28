#include <Solution.h>
#include <iostream>
#include <map>
#include <algorithm>

using std::map;
using std::max;

int Solution::minMeetingRooms2(vector<vector<int>> &intervals) {
	map<int, int> timeline;
	for (const auto &iter : intervals) {
		timeline[iter[0]] += 1;
		timeline[iter[1]] -= 1;
	}
	int maxRoom = 0;
	int Room = 0;
	for (const auto &iter : timeline) {
		Room += iter.second;
		maxRoom = max(maxRoom, Room);
	}
	return maxRoom;
}
