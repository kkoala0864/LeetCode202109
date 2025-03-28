#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

long long Solution::maxEnergyBoost(vector<int> &energyDrinkA, vector<int> &energyDrinkB) {
	int size = energyDrinkA.size();
	vector<vector<long long>> dp(size, vector<long long>(2, 0));

	dp[0][0] = energyDrinkA[0];
	dp[0][1] = energyDrinkB[0];

	for (int i = 1; i < size; ++i) {
		dp[i][0] = (long long)energyDrinkA[i] + dp[i - 1][0];
		dp[i][1] = (long long)energyDrinkB[i] + dp[i - 1][1];

		if (i > 1) {
			dp[i][0] = max(dp[i][0], (long long)energyDrinkA[i] + dp[i - 2][1]);
			dp[i][1] = max(dp[i][1], (long long)energyDrinkB[i] + dp[i - 2][0]);
		}
	}

	return max(dp.back()[0], dp.back()[1]);
}
