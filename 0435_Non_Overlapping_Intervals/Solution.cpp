#include <Solution.h>

int Solution::eraseOverlapIntervals(vector<vector<int>> &intervals) {
	auto cmp = [](const vector<int>& lhs, const vector<int>& rhs) {
		return lhs[1] == rhs[1] ? lhs[0] < rhs[0] : lhs[1] < rhs[1];
	};

	sort(intervals.begin(), intervals.end(), cmp);
	int lastTail = INT_MIN;
	int result = 0;
	for (int i = 0 ; i < intervals.size() ; ++i) {
		if (intervals[i][0] >= lastTail) {
			lastTail = intervals[i][1];
			continue;
		} else {
			++result;
		}
	}
	return result;
}
