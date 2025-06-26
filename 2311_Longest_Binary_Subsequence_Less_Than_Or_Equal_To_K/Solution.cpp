#include <Solution.h>

int Solution::longestSubsequence(string s, int k) {
	int size = s.size();
	int offset = 0;
	int result = 0;
	long long sum = 0;
	for (int i = size - 1 ; i >= 0 ; --i, ++offset) {
		if (s[i] == '0') {
			++result;
			continue;
		}

		if (offset < 32) {
			if ((sum | ((long long)1 << offset)) <= (long long)k) {
				sum = sum | 1 << offset;
				++result;
			}
		} else {
			continue;
		}
	}
	return result;

	/* DP
	int size = s.size();
	int maxLen = 0;
	vector<long long> dp(size + 1, k + 1);
	dp[0] = 0;
	for (const auto& c : s) {
		for (int i = maxLen ; i >= 0 ; --i) {
			if (dp[i] > k) continue;

			long long v = (dp[i] << 1) | (c - '0');
			if (v > k) continue;
			if (dp[i+1] > v) dp[i+1] = v;
			maxLen = max(maxLen, i + 1);
		}
	}
	return maxLen;
	*/
}
