#include <Solution.h>
#include <iostream>

int checkValid(const string& s, vector<vector<int>>& dp, int start, int end) {
	int initStart = start, initEnd = end;
	while (start <= end) {
		if (dp[start][end] != 0) return dp[start][end];
		if (s[start] != s[end]) {
			dp[initStart][initEnd] = 2;
			return dp[initStart][initEnd];
		}
		++start;
		--end;
	}
	dp[initStart][initEnd] = 1;
	return dp[initStart][initEnd];
}

void DFS(const string& s, int idx, vector<vector<int>>& dp, vector<vector<string>>& result, vector<string>& local) {
	if (idx == s.size()) {
		result.emplace_back(local);
		return;
	}

	for (int i = idx ; i < s.size() ; ++i) {
		if (s[i] == s[idx]) {
			if (checkValid(s, dp, idx, i) == 1) {
				local.emplace_back(s.substr(idx, i-idx+1));
				DFS(s, i + 1, dp, result, local);
				local.pop_back();
			}
		}
	}
}

vector<vector<string>> Solution::partition(string s) {
	vector<vector<string>> result;
	vector<string> local;
	vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
	DFS(s, 0, dp, result, local);
	return result;
}
