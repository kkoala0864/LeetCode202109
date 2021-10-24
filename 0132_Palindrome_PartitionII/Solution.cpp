#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <vector>

using std::min;
using std::vector;
/*
int checkValid(const string& s, vector<vector<int>>& dp, int start, int end) {
	int iStart = start, iEnd = end;
	while (start <= end) {
		if (dp[start][end] != 0) return dp[start][end];
		if (s[start] != s[end]) {
			dp[iStart][iEnd] = 2;
			return 2;
		}
		++start;
		--end;
	}
	dp[iStart][iEnd] = 1;
	return 1;
}

void DFS(const string& s, vector<vector<int>>& dp, int idx, int cnt, int& result) {
	if (idx == s.size()) {
		result = min(result, cnt-1);
		return;
	}

	for (int i = idx ; i < s.size() ; ++i) {
		if (s[idx] == s[i]) {
			if (checkValid(s, dp, idx, i) == 1) {
				DFS(s, dp, i+1, cnt+1, result);
			}
		}
	}
}

int Solution::minCut(string s) {
	int result = s.size();
	vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
	DFS(s, dp, 0, 0, result);
	return result;
}
*/

int isPalindrome(vector<vector<int>>& dp, const string& s, int start, int end) {
	if (dp[start][end] != 0) return dp[start][end];
	int iStart = start, iEnd = end;
	while (start <= end) {
		if (dp[start][end] != 0) return dp[start][end];
		if (s[start++] != s[end--]) {
			dp[iStart][iEnd] = 2;
			return 2;
		}
	}
	dp[iStart][iEnd] = 1;
	return 1;
}


int findMinCut(vector<vector<int>>& dp, vector<vector<int>>& dpCut, const string& s, int start, int end, int minCut) {
	if (start == end || isPalindrome(dp, s, start, end) == 1) {
		return 0;
	}

	if (dpCut[start][end] != -1) {
		return dpCut[start][end];
	}

	for (int i = start ; i <= end ; ++i) {
		if (isPalindrome(dp, s, start, i) == 1) {
			minCut = min(minCut, 1 + findMinCut(dp, dpCut, s, i + 1, end, minCut));
		}
	}
	dpCut[start][end] = minCut;
	return minCut;
}

int Solution::minCut(string s) {
	vector<vector<int>> dpCut(s.size(), vector<int>(s.size(), -1));
	vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
	return findMinCut(dp, dpCut, s, 0, s.size()-1, s.size()-1);
}
