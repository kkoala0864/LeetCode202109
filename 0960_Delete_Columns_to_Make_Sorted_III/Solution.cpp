#include <Solution.h>

bool check(vector<string>& strs, int i, int j) {
	int size = strs.size();
	for (const auto& s : strs) {
		if (s[i] < s[j]) return false;
	}
	return true;
}

int Solution::minDeletionSize(vector<string>& strs) {
	int size = strs[0].size();
	vector<int> dp(size, 1);

	for (int i = 1 ; i < size ; ++i) {
		for (int j = 0 ; j < i ; ++j) {
			if (check(strs, i, j)) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	int maxLen = 0;
	for (const auto& v : dp) maxLen = max(maxLen, v);
	return size - maxLen;
}
