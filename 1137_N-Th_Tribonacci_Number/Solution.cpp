#include <Solution.h>
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::max;

int Solution::tribonacci(int n) {
	vector<int> dp(max(n+1,3) , 0);
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3 ; i <= n ; ++i) {
		dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
	}
	return dp[n];
}
