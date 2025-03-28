#include <Solution.h>
#include <iostream>
#include <map>
#include <algorithm>

using std::map;
using std::max;

int Solution::minMeetingRooms3(vector<vector<int>> &intervals) {
	map<int, int> timeline;
	for (const auto &iter : intervals) {
		++timeline[iter[0]];
		--timeline[iter[1]];
	}

	int peak = 0;
	int cnt = 0;
	for (const auto &iter : timeline) {
		cnt += iter.second;
		peak = max(peak, cnt);
	}
	return peak;
}
