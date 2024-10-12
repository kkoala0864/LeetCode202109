#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

int Solution::minGroups(vector<vector<int>>& intervals) {
	vector<int> room(1000002, 0);
	int maxIdx = 0;

	for (const auto& i : intervals) {
		++room[i[0]];
		--room[i[1]+1];
		maxIdx = max(maxIdx, i[1] + 1);
	}
	int result = 1;
	int cur = 0;
	for (int i = 0 ; i <= maxIdx ; ++i) {
		cur += room[i];
		result = max(cur, result);
	}
	return result;
}
