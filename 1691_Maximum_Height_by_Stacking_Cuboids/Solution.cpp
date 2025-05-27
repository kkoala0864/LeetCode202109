#include <Solution.h>

int Solution::maxHeight(vector<vector<int>>& cuboids) {
	for (auto& c : cuboids) {
		sort(c.begin(), c.end());
	}
	sort(cuboids.begin(), cuboids.end());

	int result = 0;
	vector<int> dp(cuboids.size(), 0);
	for (int i = 0 ; i < cuboids.size() ; ++i) {
		for (int j = 0 ; j < i ; ++j) {
			int k = 0;
			for (; k < 3 ; ++k) {
				if (cuboids[i][k] < cuboids[j][k]) break;
			}
			if (k < 3) continue;
			dp[i] = max(dp[i], dp[j]);
		}
		dp[i] += cuboids[i][2];
		result = max(result, dp[i]);
	}
	return result;

}
