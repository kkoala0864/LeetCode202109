#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;
using std::sort;

int Solution::countDays(int days, vector<vector<int>>& meetings) {
	sort(meetings.begin(), meetings.end());
	vector<int> cur = meetings[0];
	int md = 0;
	for (int i = 1 ; i < meetings.size() ; ++i) {
		if (cur[1] < meetings[i][0]) {
			md += (cur[1] - cur[0] + 1);
			cur = meetings[i];
		} else {
			cur[1] = max(cur[1], meetings[i][1]);
		}
	}
	md += (cur[1] - cur[0] + 1);
	return days - md;
}
