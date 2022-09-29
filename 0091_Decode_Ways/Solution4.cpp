#include <Solution.h>
#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

int Solution::numDecodings4(string s) {
	if (s[0] == '0') return 0;

	vector<int> dp(s.size() + 1, 0);
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 1 ; i < s.size() ; ++i) {
		if (s[i] == '0') {
			if (s[i-1]-'0' <= 2 && s[i-1] != '0') dp[i+1] += dp[i-1];
		} else {
			dp[i+1] += dp[i];
			if ((s[i]-'0' <= 9 && s[i-1] == '1') ||
			    (s[i]-'0' <= 6 && s[i-1] == '2')) dp[i+1] += dp[i-1];
		}
	}
	return dp[s.size()];
}
