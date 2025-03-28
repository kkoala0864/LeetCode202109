#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;
using std::min;

vector<vector<int>> Solution::merge4(vector<vector<int>> &intervals) {
	vector<vector<int>> result;

	sort(intervals.begin(), intervals.end());
	for (int i = 0; i < intervals.size(); ++i) {
		int j = i + 1;
		while (j < intervals.size()) {
			if (intervals[i][1] < intervals[j][0]) {
				break;
			} else {
				intervals[i][0] = min(intervals[i][0], intervals[j][0]);
				intervals[i][1] = max(intervals[i][1], intervals[j][1]);
			}
			++j;
		}
		result.emplace_back(intervals[i]);
		i = j - 1;
	}
	return result;
}
