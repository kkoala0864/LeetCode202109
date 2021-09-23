#include <Solution.h>
#include <iostream>
#include <vector>
using std::vector;

bool twoCheck(const string& s, int i) {
	if ((s[i-1] == '0') ||
	    (s[i-1] > '2') ||
	    (s[i-1] == '2' && s[i] > '6')) return false;
	return true;
}

int Solution::numDecodings(string s) {
	vector<int> dp(s.size()+1, 0);

	dp[0] = (s[0] == '0') ? 0 : 1;

	if (s[1] != '0') dp[1] = dp[0];
	dp[1] = twoCheck(s, 1) ? 1 + dp[1] : dp[1];

	for (int i = 2 ; i < s.size() ; ++i) {
		if (s[i] != '0') { dp[i] = dp[i-1]; }
		if (twoCheck(s, i)) { dp[i] += dp[i-2]; }
	}
	return dp[s.size()-1];
}
