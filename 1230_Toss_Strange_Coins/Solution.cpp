#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

double Solution::probabilityOfHeads(vector<double>& prob, int target) {
	vector<double> dp(target + 1, 0);

	dp[0] = 1;
	for (int i = 0 ; i < prob.size() ; ++i) {
		vector<double> tmp = dp;
		for (int j = 0 ; j <= target ; ++j) {
			tmp[j] = dp[j] * (1-prob[i]);
			if (j > 0) {
				tmp[j] += dp[j-1] * prob[i];
			}
		}
		dp = move(tmp);
	}
	return dp[target];
}
