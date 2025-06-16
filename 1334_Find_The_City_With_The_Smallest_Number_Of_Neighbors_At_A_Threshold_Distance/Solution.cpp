#include <Solution.h>

int Solution::findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold) {
	vector<vector<int>> minCost(n, vector<int>(n, INT_MAX/2));

	for (const auto& e : edges) {
		minCost[e[0]][e[1]] = e[2];
		minCost[e[1]][e[0]] = e[2];
	}
	for (int i = 0 ; i < n ; ++i) minCost[i][i] = 0;

	vector<int> cnt(n, 0);
	int minCnt = INT_MAX;
	int result = 0;
	for (int k = 0 ; k < n ; ++k) {
		for (int i = 0 ; i < n ; ++i) {
			for (int j = 0 ; j < n ; ++j) {
				if (i == j) continue;
				if (minCost[i][j] > (minCost[i][k] + minCost[k][j])) {
					minCost[i][j] = minCost[i][k] + minCost[k][j];
				}
			}
		}
	}
	for(int i = 0 ; i < n ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			if (minCost[i][j] <= distanceThreshold) {
				++cnt[i];
			}
		}
	}
	for (int i = 0 ; i < n ; ++i) {
		if (minCnt == cnt[i]) {
			result = i;
		} else if (minCnt > cnt[i]) {
			minCnt = cnt[i];
			result = i;
		}
	}
	return result;
}
