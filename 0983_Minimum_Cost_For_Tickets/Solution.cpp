#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::min;

int Solution::mincostTickets(vector<int>& days, vector<int>& costs) {
	int size = days.size();
	vector<int> offset({1, 7, 30});
	vector<int> dp;

	for (int i = 0 ; i < size ; ++i) {
		int curMin = INT_MAX;
		for (int oi = 0 ; oi < 3 ; ++oi) {
			int j = i - 1;
			for (; j >= 0 && (days[i] - days[j]) < offset[oi] ; --j) {}
			int v = j >= 0 ? dp[j] : 0;
			v += costs[oi];
			curMin = min(curMin, v);
		}
		dp.emplace_back(curMin);
	}
	return dp.back();

}
