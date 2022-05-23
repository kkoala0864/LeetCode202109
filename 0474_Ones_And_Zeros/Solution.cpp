#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

int Solution::findMaxForm(vector<string>& strs, int m, int n) {
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
	vector<vector<int>> next;
	int result = 0;
	for (const auto& str : strs) {
		int zCnt = 0, oCnt = 0;
		next = dp;
		for (const auto& c : str) {
			if (c == '0') ++zCnt;
			else ++oCnt;
		}
		if (zCnt > m || oCnt > n) continue;
		for (int i = 0 ; i <= (m - zCnt) ; ++i) {
			for (int j = 0 ; j <= (n - oCnt) ; ++j) {
				if (dp[i][j] == 0) continue;
				int nz = zCnt + i;
				int no = oCnt + j;
				if (nz > m || no > n) continue;
				next[nz][no] = max(dp[nz][no], dp[i][j] + 1);
				result = max(result, next[nz][no]);
			}
		}
		next[zCnt][oCnt] = max(dp[zCnt][oCnt], 1);
		result = max(next[zCnt][oCnt], result);
		dp = move(next);
	}
	return result;
}
