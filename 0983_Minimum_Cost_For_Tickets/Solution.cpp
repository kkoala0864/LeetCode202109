#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::min;

int Solution::mincostTickets(vector<int>& days, vector<int>& costs) {
	int size = days.size();
	vector<int> offset = {1, 7, 30};
	vector<int> dp(size, INT_MAX);
	for (int i = 0 ; i < size ; ++i) {
		for (int oi = 0 ; oi < 3 ; ++oi) {
			int td = days[i] - offset[oi];
			int lastDay = lower_bound(days.begin(), days.begin() + i, td) - days.begin();
			if (days[lastDay] > td) --lastDay;
			int lastCost = lastDay == -1 ? 0 : dp[lastDay];
			dp[i] = min(dp[i], lastCost + costs[oi]);
		}
	}
	return dp.back();
}
