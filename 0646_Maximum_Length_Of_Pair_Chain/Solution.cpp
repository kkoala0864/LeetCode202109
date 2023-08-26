#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;
using std::max;

int Solution::findLongestChain(vector<vector<int>>& pairs) {
	sort(pairs.begin(), pairs.end());

	vector<int> dp(pairs.size(), 1);

	int result = 0;
	for (int i = 0 ; i < pairs.size() ; ++i) {
		for (int j = 0 ; j < i ; ++j) {
			if (pairs[i][0] > pairs[j][1]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		result = max(result, dp[i]);
	}
	return result;
}
