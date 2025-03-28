#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::max;
using std::min;

int Solution::maxDistance(vector<vector<int>> &arrays) {
	int curMax = arrays[0].back();
	int curMin = arrays[0][0];
	int result = 0;

	for (int i = 1; i < arrays.size(); ++i) {
		result = max({result, abs(curMax - arrays[i][0]), abs(arrays[i].back() - curMin)});
		curMax = max(curMax, arrays[i].back());
		curMin = min(curMin, arrays[i][0]);
	}
	return result;
}
