#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;
using std::sort;

int Solution::jobScheduling2(vector<int> &startTime, vector<int> &endTime, vector<int> &profit) {
	vector<vector<int>> t;

	vector<int> dp;
	vector<int> p;

	for (int i = 0; i < startTime.size(); ++i) {
		t.emplace_back(vector<int>({endTime[i], startTime[i], profit[i]}));
	}

	sort(t.begin(), t.end());
	int curMax = 0;

	for (const auto &v : t) {
		int idx = upper_bound(dp.begin(), dp.end(), v[1]) - dp.begin();
		int lastMaxProfit = 0;
		if (idx != 0) {
			--idx;
			lastMaxProfit = p[idx];
		}

		curMax = max(lastMaxProfit + v[2], curMax);
		dp.emplace_back(v[0]);
		p.emplace_back(curMax);
	}
	return curMax;
}
