#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

int Solution::minRefuelStops(int target, int startFuel, vector<vector<int>> &stations) {
	int n = stations.size();

	vector<long> dp(n + 1, 0);

	dp[0] = startFuel;

	for (int i = 0; i < n; ++i) {
		for (int t = i; t >= 0; --t) {
			if (dp[t] >= stations[i][0]) {
				dp[t + 1] = max(dp[t + 1], dp[t] + stations[i][1]);
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		if (dp[i] >= target)
			return i;
	}
	return -1;
}
