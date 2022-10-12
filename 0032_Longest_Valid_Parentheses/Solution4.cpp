#include <Solution.h>
#include <iostream>
#include <stack>
#include <vector>

using std::max;
using std::vector;
using std::cout;
using std::endl;


// ()()
// (())
int Solution::longestValidParentheses4(string s) {
	vector<int> dp(s.size(), 0);
	int result = 0;

	for (int i = 1 ; i < s.size() ; ++i) {
		if (s[i] == '(') continue;
		if (s[i] == ')') {
			int size = dp[i-1];
			int leftIdx = i - size - 1;
			if (leftIdx < 0) continue;
			if (s[leftIdx] == '(') {
				dp[i] = max(dp[i], size + 2);
				if (leftIdx - 1 >= 0) dp[i] += dp[leftIdx-1];
			}
		}
		result = max(result, dp[i]);
	}
	return result;
}
