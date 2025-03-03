#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <vector>

using std::max;
using std::min;
using std::cout;
using std::endl;
using std::vector;

int distance(char& lhs, char& rhs) {
	return min((lhs - rhs + 26) % 26, (rhs - lhs + 26) % 26);
}

int Solution::longestPalindromicSubsequence(string s, int k) {
	int size = s.size();
	vector<vector<vector<int>>> dp(size + 1, vector<vector<int>>(size + 1, vector<int>(k + 1, 0)));

	for (int i = 0 ; i < size ; ++i) {
		for (int ki = 0 ; ki <= k ; ++ki) {
			dp[i][i][ki] = 1;
		}
	}
	int result = 1;
	for (int sz = 2 ; sz <= size ; ++sz) {
		for (int i = 0 ; (i + sz) <= size ; ++i) {
			int j = i + sz - 1;
			int dis = distance(s[i], s[j]);
			for (int ki = 0 ; ki <= k ; ++ki) {
				dp[i][j][ki] = max(dp[i+1][j][ki], dp[i][j-1][ki]);
				if (ki >= dis) {
					dp[i][j][ki] = max(dp[i][j][ki], dp[i+1][j-1][ki-dis] + 2);
				}

			}
		}
	}
	return dp[0][size-1][k];
}
