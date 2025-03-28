#include <Solution.h>
#include <iostream>
#include <climits>
#include <algorithm>

using std::min;

int Solution::canCompleteCircuit3(vector<int> &gas, vector<int> &cost) {
	int totalDiff = 0;
	int curDiff = 0;
	int result = INT_MAX;

	for (int i = 0; i < gas.size(); ++i) {
		int diff = gas[i] - cost[i];
		if (curDiff + diff < 0) {
			curDiff = 0;
			result = INT_MAX;
		} else {
			curDiff += diff;
			result = min(result, i);
		}
		totalDiff += diff;
	}
	return result == INT_MAX || totalDiff < 0 ? -1 : result;
}
