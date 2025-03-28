#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;
using std::min;
using std::sort;

vector<int> Solution::minAvailableDuration(vector<vector<int>> &slots1, vector<vector<int>> &slots2, int duration) {
	sort(slots1.begin(), slots1.end());
	sort(slots2.begin(), slots2.end());

	int it1 = 0, it2 = 0;
	while (it1 < slots1.size() && it2 < slots2.size()) {
		int l = max(slots1[it1][0], slots2[it2][0]), r = min(slots1[it1][1], slots2[it2][1]);

		if ((r - l) >= duration)
			return {l, min(r, l + duration)};

		if (slots1[it1][1] < slots2[it2][1])
			++it1;
		else
			++it2;
	}
	return {};
}
