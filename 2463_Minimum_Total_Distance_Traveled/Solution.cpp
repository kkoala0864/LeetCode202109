#include <Solution.h>
#include <iostream>
#include <algorithm>

long long Solution::minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
	sort(robot.begin(), robot.end());
	sort(factory.begin(), factory.end());

	// dp[i][j] : factory i cover j robots
	int rs = robot.size();
	int fs = factory.size();
	vector<vector<vector<long long>>> dist(fs, vector<vector<long long>>(rs, vector<long long>(rs, 0)));

	for (int i = 0 ; i < fs ; ++i) {
		for (int j = 0 ; j < rs ; ++j) {
			long long sum = 0;
			for (int k = j ; k < rs ; ++k) {
				sum += abs(factory[i][0] - robot[k]);
				dist[i][j][k] = sum;
			}
		}
	}

	vector<vector<long long>> dp(fs, vector<long long>(rs + 1, 0));

	dp[0][0] = 0;
	for (int j = 1 ; j <= rs ; ++j) {
		if (j <= factory[0][1]) {
			dp[0][j] = dist[0][0][j-1];
		} else {
			dp[0][j] = LLONG_MAX / 2;
		}
	}

	for (int i = 1 ; i < fs ; ++i) {
		for (int j = 1 ; j <= rs ; ++j) {
			dp[i][j] = dp[i-1][j];
			for (int k = 1 ; k <= min(factory[i][1], j) ; ++k) {
				dp[i][j] = min(dp[i][j], dp[i-1][j-k] + dist[i][j-k][j-1]);
			}
		}
	}
	return dp[fs-1][rs];
}
