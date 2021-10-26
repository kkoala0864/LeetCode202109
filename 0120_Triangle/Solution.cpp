#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::min;

int Solution::minimumTotal(vector<vector<int>>& triangle) {
	int size = triangle.size();
	vector<int> dp(triangle[size-1].size(), 0);
	for (int i = 0 ; i < triangle[size-1].size() ; ++i) {
		dp[i] = triangle[size-1][i];
	}

	for (int i = size - 2 ; i >= 0 ; --i) {
		for (int j = 0 ; j < triangle[i].size() ; ++j) {
			dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
		}
	}
	return dp[0];
}
