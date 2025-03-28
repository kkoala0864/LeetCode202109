#include <Solution.h>
#include <vector>
using std::vector;

int check(const string &s, int idx, int size) {
	if (size == 1) {
		return s[idx] == '0' ? 0 : 1;
	} else {
		if (s[idx - 1] == '0' || s[idx - 1] >= '3')
			return 0;
		else if (s[idx - 1] == '1') {
			return s[idx] >= '0' && s[idx] <= '9' ? 1 : 0;
		} else if (s[idx - 1] == '2') {
			return s[idx] >= '0' && s[idx] <= '6' ? 1 : 0;
		}
		return 0;
	}
}

int Solution::numDecodings2(string s) {
	if (s.empty())
		return 0;
	vector<int> dp(s.size() + 1, 0);

	dp[0] = 1;
	dp[1] = s[0] == '0' ? 0 : 1;
	for (int i = 1; i < s.size(); ++i) {
		dp[i + 1] = dp[i] * check(s, i, 1) + dp[i - 1] * check(s, i, 2);
	}
	return dp[s.size()];
}
