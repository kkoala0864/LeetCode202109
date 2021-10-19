#include <Solution.h>
#include <iostream>
#include <climits>
#include <algorithm>

using std::min;

int Solution::canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
	int start = INT_MAX;
	int total = 0;
	int rest = 0;
	for (int i = 0 ; i < gas.size() ; ++i) {
		int diff = (gas[i] - cost[i]);
		rest += diff;
		total += diff;
		if (rest < 0) {
			start = INT_MAX;
			rest = 0;
		} else {
			start = min(start, i);
		}
	}

	return total >= 0 ? start == INT_MAX ? -1 : start : -1;
}

