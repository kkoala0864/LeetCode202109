#include <Solution.h>
#include <iostream>
#include <vector>
using std::vector;

int Solution::numDecodings4(string s) {
	vector<int> dp(s.size() + 1, 0);

	dp[0] = 1;
	for (int i = 0 ; i < s.size() ; ++i) {
		int v = s[i] - '0';
		if (v > 0) dp[i+1] += dp[i];
		if (i > 0) {
			int prev = s[i-1] - '0';
			if (prev == 1 || prev == 2 && v <= 6) {
				dp[i+1] += dp[i-1];
			}
		}
	}
	return dp.back();
}
