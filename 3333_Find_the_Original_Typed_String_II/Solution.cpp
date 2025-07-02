#include <Solution.h>

int Solution::possibleStringCount(string word, int k) {
	int n = word.size(), cnt = 1;
	vector<long long> freq(1, 1);
	long long mod = 1e9 + 7;

	for (int i = 1; i < n; ++i) {
		if (word[i] == word[i - 1]) {
			++freq.back();
		} else {
			freq.emplace_back(1);
		}
	}

	long long ans = 1;
	for (const auto& f : freq) {
		ans = ans * f % mod;
	}

	if (freq.size() >= k) {
		return ans;
	}

	vector<long long> dp(k, 0), preSum(k, 1);
	dp[0] = 1;

	for (int i = 0; i < freq.size(); ++i) {
		vector<long long> next(k);
		for (int j = 1; j < k; ++j) {
			// next[j] : len j
			// preSum[j-1] : 0 ~ j-1 => len j
			next[j] = preSum[j - 1];
			if (j - freq[i] - 1 >= 0) {
				next[j] = (next[j] - preSum[j - freq[i] - 1] + mod) % mod;
			}
		}
		vector<long long> nextPreSum(k);
		nextPreSum[0] = next[0];
		for (int j = 1; j < k; ++j) {
			nextPreSum[j] = (nextPreSum[j - 1] + next[j]) % mod;
		}
		dp = move(next);
		preSum = move(nextPreSum);
	}
	return (ans - preSum[k - 1] + mod) % mod;
}
