#include <Solution.h>

// record index
// iterate word
// dp[i] = max(dp[i], (past idx) + 1);
int Solution::maxSubstrings(string word) {
	int size = word.size();
	vector<int> dp(size + 1, 0);

	for (int i = 0 ; i < size ; ++i) {
		dp[i+1] = dp[i];
		for (int j = i - 1 ; j >= 0 ; --j) {
			if (word[i] != word[j]) continue;
			if ((i - j + 1) < 4) continue;
			dp[i+1] = max({dp[i+1], dp[j] + 1});
			break;
		}
	}
	return dp.back();
}
