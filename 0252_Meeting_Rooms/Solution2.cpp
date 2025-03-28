#include <Solution.h>
#include <iostream>
#include <map>

using std::map;

bool Solution::canAttendMeetings2(vector<vector<int>> &intervals) {
	map<int, int> timeline;
	for (const auto &iter : intervals) {
		++timeline[iter[0]];
		--timeline[iter[1]];
	}

	int cnt = 0;
	for (const auto &iter : timeline) {
		cnt += iter.second;
		if (cnt > 1)
			return false;
	}
	return true;
}
