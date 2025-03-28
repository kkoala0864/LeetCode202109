#include <Solution.h>
#include <iostream>
#include <stack>
#include <vector>

using std::max;
using std::stack;
using std::vector;

int Solution::DP(string s) {
	vector<int> dp(s.size(), 0);
	int result = 0;

	for (int i = 1; i < s.size(); ++i) {
		if (s[i] == '(')
			dp[i] = 0;
		else {
			if (s[i - 1] == '(')
				dp[i] = i >= 2 ? dp[i - 2] + 2 : 2;
			else if ((i - dp[i - 1] > 0) && s[i - dp[i - 1] - 1] == '(')
				dp[i] = dp[i - 1] + (i - dp[i - 1] >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
		}
		result = max(result, dp[i]);
	}
	return result;
}

int Solution::longestValidParentheses3(string s) {
	stack<int> st;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '(')
			st.emplace(i);
		else {
			if (st.empty())
				continue;
			else {
				s[st.top()] = 'a';
				st.pop();
				s[i] = 'a';
			}
		}
	}
	int result = 0;
	int cnt = 0;
	for (const auto &c : s) {
		if (c == 'a') {
			++cnt;
		} else {
			result = max(result, cnt);
			cnt = 0;
		}
	}
	result = max(result, cnt);
	return result;
}
