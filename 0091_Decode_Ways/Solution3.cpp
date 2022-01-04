#include <Solution.h>
#include <iostream>
#include <vector>
using std::vector;

int check2(const string& s, int idx, int size) {
	if (size == 1) {
		return s[idx] == '0' ? 0 : 1;
	} else {
		if (s[idx-1] == '0' || s[idx-1] > '2') {
			return 0;
		} else if (s[idx-1] == '2' && s[idx] > '6') {
			return 0;
		}
	}
	return 1;
}

int Solution::numDecodings3(string s) {
	if (s.empty()) return 0;
	vector<int> dp(s.size()+1, 0);
	dp[0] = 1;
	dp[1] = s[0] == '0' ? 0 : 1;
	for (int i = 2 ; i <= s.size() ; ++i) {
		dp[i] = dp[i-1] * check2(s, i-1, 1) + dp[i-2] * check2(s, i-1, 2);
	}
	return dp[s.size()];
}
