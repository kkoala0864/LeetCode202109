#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::max;
using std::min;

int Solution::smallestCommonElement(vector<vector<int>> &mat) {
	int start = 0, end = INT_MAX;

	for (const auto &m : mat) {
		start = max(start, m[0]);
		end = min(end, m.back());
	}

	int curVal = start;
	bool change = false;
	while (curVal <= end) {
		change = false;
		for (const auto &m : mat) {
			int idx = lower_bound(m.begin(), m.end(), curVal) - m.begin();
			if (idx == m.size())
				return -1;
			if (m[idx] == curVal)
				continue;
			curVal = m[idx];
			change = true;
		}
		if (!change)
			return curVal;
	}
	return -1;
}
