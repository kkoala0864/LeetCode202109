#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;
using std::min;

vector<vector<int>> Solution::merge2(vector<vector<int>> &intervals) {
	vector<vector<int>> tmp;
	while (true) {
		bool change = false;
		for (int i = 0; i < intervals.size(); ++i) {
			int j = i + 1;
			for (; j < intervals.size(); ++j) {
				if (intervals[i][0] > intervals[j][1]) {
					tmp.emplace_back(intervals[j]);
					change = true;
				} else if (intervals[i][1] >= intervals[j][0]) {
					intervals[i][0] = min(intervals[i][0], intervals[j][0]);
					intervals[i][1] = max(intervals[i][1], intervals[j][1]);
					change = true;
				} else {
					break;
				}
			}
			tmp.emplace_back(intervals[i]);
			i = j - 1;
		}
		if (!change)
			break;
		intervals = move(tmp);
	}
	return intervals;
}
