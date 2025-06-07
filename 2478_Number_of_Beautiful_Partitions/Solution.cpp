#include <Solution.h>
// dp[i] = possibility end with i
// dp[i] += (dp[i-minLength] % mod)
bool isPrime(char c) {
	return c == '2' || c == '3' || c == '5' || c == '7';
}

int Solution::beautifulPartitions(string s, int k, int minLength) {
	if (!isPrime(s[0]) || isPrime(s.back())) return 0;

	int size = s.size();
	vector<long long> dp(size + 1, 0);
	dp[0] = 1;
	long long mod = 1e9 + 7;

	for (int i = 1 ; i <= k ; ++i) {
		vector<long long> next(size + 1, 0);
		long long preSum = 0;
		for (int j = 0 ; j < s.size() ; ++j) {
			int start = j - minLength + 1;
			if (start >= 0 && isPrime(s[start])) {
				preSum += dp[start];
				preSum %= mod;
			}

			if (!isPrime(s[j])) {
				next[j + 1] = preSum;
			}
		}
		dp = std::move(next);
	}

	return dp.back();
}
