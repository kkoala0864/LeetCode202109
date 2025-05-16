#include <Solution.h>

// dp[i] = minimum sum of schedule util i
// dp[i] = min(dp[i], dp[j-1] + max(job[j:i]));

int Solution::minDifficulty(vector<int> &jobDifficulty, int d) {
	int size = jobDifficulty.size();
	if (size < d) return -1;

	vector<int> dp(size, INT_MAX);

	dp[0] = jobDifficulty[0];
	for (int i = 1 ; i < size ; ++i) {
		dp[i] = max(dp[i-1], jobDifficulty[i]);
	}

	for (int di = 1 ; di < d ; ++di) {
		vector<int> next(size, INT_MAX);
		for (int i = di ; i < size ; ++i) {
			int maxValue = 0;
			for (int j = i ; j >= di ; --j) {
				maxValue = max(maxValue, jobDifficulty[j]);
				if (dp[j-1] != INT_MAX) {
					next[i] = min(next[i], dp[j-1] + maxValue);
				}
			}
		}
		dp = move(next);
	}
	return dp.back();
}
