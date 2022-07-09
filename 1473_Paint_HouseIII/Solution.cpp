#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::min;

int Solution::minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
	vector<vector<vector<int>>> dp(target+1, vector<vector<int>>(m, vector<int>(n, INT_MAX)));

	if (houses[0] == 0) {
		for (int i = 0 ; i < n ; ++i) dp[1][0][i] = cost[0][i];
	} else {
		dp[1][0][houses[0] - 1] = 0;
	}

	for (int hi = 1 ; hi < m ; ++hi) {
		int cIStart = houses[hi] == 0 ? 0 : houses[hi]-1;
		int cIEnd = houses[hi] == 0 ? n : houses[hi];

		for (int ti = 1 ; ti <= target ; ++ti) {
			for (int ci = cIStart ; ci < cIEnd ; ++ci) {
				for (int lci = 0 ; lci < n ; ++lci) {
					if (lci == ci) {
						if (dp[ti][hi-1][ci] == INT_MAX) continue;
						dp[ti][hi][ci] = min(dp[ti][hi][ci], dp[ti][hi-1][ci] + (houses[hi] == 0 ? cost[hi][ci] : 0));
					} else {
						if (ti + 1 <= target) {
							if (dp[ti][hi-1][lci] == INT_MAX) continue;
							dp[ti+1][hi][ci] = min(dp[ti+1][hi][ci], dp[ti][hi-1][lci] + (houses[hi] == 0 ? cost[hi][ci] : 0));
						}
					}
				}
			}
		}
	}

	int result = INT_MAX;
	for (int i = 0 ; i < n ; ++i) result = min(result, dp[target][m-1][i]);
	return result == INT_MAX ? -1 : result;
}
