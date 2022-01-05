#include <Solution.h>
#include <iostream>

void isPalindrome(const string& s, int start, int end, vector<vector<int>>& dp) {
	int i = start;
	int j = end;
	while (i <= j) {
		if (s[i++] != s[j--]) {
			dp[start][end] = 2;
			return;
		}
	}
	dp[start][end] = 1;
}

void dfs(const string& s, int idx, vector<string>& local, vector<vector<string>>& result, vector<vector<int>>& dp) {
	if (idx == s.size()) {
		result.emplace_back(local);
		return;
	}

	for (int i = idx ; i < s.size() ; ++i) {
		if (dp[idx][i] == 0) isPalindrome(s, idx, i, dp);
		if (dp[idx][i] == 1) {
			local.push_back(s.substr(idx, i - idx + 1));
			dfs(s, i+1, local, result, dp);
			local.pop_back();
		}
	}
}

vector<vector<string>> Solution::partition2(string s) {
	vector<vector<string>> result;
	vector<string> local;
	vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
	dfs(s, 0, local, result, dp);
	return result;
}
