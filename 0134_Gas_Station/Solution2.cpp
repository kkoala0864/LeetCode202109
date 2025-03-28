#include <Solution.h>
#include <iostream>
#include <climits>
#include <algorithm>

using std::min;

int Solution::canCompleteCircuit2(vector<int> &gas, vector<int> &cost) {
	int totalDiff = 0;
	int curDiff = 0;
	int start = INT_MAX;

	for (int i = 0; i < gas.size(); ++i) {
		int idx = i;
		int diff = gas[idx] - cost[idx];
		if ((curDiff + diff) < 0) {
			curDiff = 0;
			start = INT_MAX;
		} else {
			curDiff += diff;
			start = min(start, i);
		}
		totalDiff += diff;
	}
	return start == INT_MAX || totalDiff < 0 ? -1 : start % gas.size();
}
