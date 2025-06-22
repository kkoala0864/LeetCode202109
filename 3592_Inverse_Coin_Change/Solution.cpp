#include <Solution.h>

vector<int> Solution::findCoins(vector<int>& numWays) {
	vector<int> dp(101, 0);
	dp[0] = 1;
	vector<int> result;
	for (int i = 0 ; i < numWays.size() ; ++i) {
		int curV = i + 1;
		if (dp[curV] != numWays[i]) {
			result.emplace_back(curV);
			for (int i = curV ; i <= 100 ; ++i) {
				dp[i] += dp[i-curV];
			}
			if (dp[curV] != numWays[i]) return vector<int>();
		}
	}
	return result;
}
