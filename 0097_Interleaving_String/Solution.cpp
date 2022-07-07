#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;
using std::max;
using std::min;

bool Solution::isInterleave(string s1, string s2, string s3) {
	int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
	if (n1 + n2 < n3) return false;
	vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1, false));
	dp[0][0] = true;

	for (int i = 1 ; i <= n3 ; ++i) {
		int idx = max(0, i-n2-1);
		int idxEnd = min(i-1, n1);
		for (; idx <= idxEnd ; ++idx) {
			if (dp[idx][i-idx-1]) {
				if (idx < n1 && s1[idx] == s3[i-1]) {
					dp[idx+1][i-idx-1] = true;
				}
				if (i-idx-1 < n2 && s2[i-idx-1] == s3[i-1]) {
					dp[idx][i-idx] = true;
				}
			}
		}
	}
	return dp[n1][n2];
}
