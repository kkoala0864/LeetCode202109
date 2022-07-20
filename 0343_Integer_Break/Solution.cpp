#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;
using std::max;

int Solution::integerBreak(int n) {
	vector<int> dp(n+1, 0);
	dp[1] = 1;
	dp[2] = 1;

	for (int i = 3 ; i <= n ; ++i) {
		for (int j = 1 ; j < i ; ++j) {
			dp[i] = max(dp[i], dp[j] * dp[i-j]);
			dp[i] = max(dp[i], dp[j] * (i-j));
			dp[i] = max(dp[i], j * dp[i-j]);
			dp[i] = max(dp[i], j*(i-j));
		}
	}
	return dp[n];
}
