#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

int Solution::countVowelStrings(int n) {
	vector<int> dp(5, 0);
	for (int i = 0; i < n; ++i) {
		for (int j = 4; j >= 0; --j) {
			if (i == 0)
				dp[j] = j + 1;
			else {
				int val = 0;
				for (int k = j - 1; k >= 0; --k) {
					dp[j] += dp[k];
				}
			}
		}
	}
	return dp[4];
}
