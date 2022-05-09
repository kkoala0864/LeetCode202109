#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

int Solution::countTexts(string s) {
	int mod = 1e9 + 7;
	int n = s.length();
	vector<long long> dp(n+1, 1);
	int limit = 0;

	for (int i = n-2 ; i >= 0 ; --i) {
		limit = (s[i] == '7' || s[i] == '9') ? 4 : 3;
		long long ans = dp[i+1];
		int j = i+1;
		int count = 1;
		while (j < n && s[j] == s[j-1] && count < limit) {
			count++;
			ans += dp[j+1];
			ans %= mod;
			j++;
		}
		dp[i] = ans;
	}
	return dp[0];
}
