#include <Solution.h>
#include <iostream>
#include <stack>
#include <vector>

using std::max;
using std::vector;
// (())
// ()()
int Solution::longestValidParentheses5(string s) {
	vector<int> dp(s.size(), 0);
	int result = 0;

	for (int i = 1; i < s.size(); ++i) {
		if (s[i] == '(')
			continue;
		int size = dp[i - 1];
		int leftIdx = i - size - 1;

		if (leftIdx < 0)
			continue;
		if (s[leftIdx] == '(') {
			dp[i] = dp[i - 1] + 2;
			if (leftIdx - 1 >= 0)
				dp[i] += dp[leftIdx - 1];
		}
		result = max(result, dp[i]);
	}
	return result;
}
