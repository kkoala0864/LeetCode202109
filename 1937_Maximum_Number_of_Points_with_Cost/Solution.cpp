#include <Solution.h>

// k is (i - 1) idx
// j is i idx
// dp[i][j] = points[i][j] + max(dp[i][k] - abs(k - j));
// dp[i][j] = points[i][j] + max(dp[i][k] - (k - j), dp[i][k] - (j - k));
//                                          k >= j            k <= j
// dp[i][j] = points[i][j] + max(dp[i][k] - k + j, dp[i][k] + k - j);
// k >= j : j is current -> right side
// k <= j : j is current -> left side
long long Solution::maxPoints(vector<vector<int>>& points) {
	int m = points.size();
	int n = points[0].size();

	vector<long long> dp(n, INT_MIN), next(n, INT_MIN);
	for (int i = 0 ; i < n ; ++i) dp[i] = points[0][i];

	for (int i = 1 ; i < m ; ++i) {
		vector<long long> left(n, INT_MIN), right(n, INT_MIN);

		left[0] = dp[0];
		for (int k = 1 ; k < n ; ++k) {
			left[k] = max(left[k-1], dp[k] + k);
		}

		right[n-1] = dp[n-1] - (n-1);
		for (int k = n - 2 ; k >= 0 ; --k) {
			right[k] = max(right[k+1], dp[k] - k);
		}

		for (int j = 0 ; j < n ; ++j) {
			next[j] = points[i][j] + max(left[j] - j, right[j] + j);
		}
		swap(dp, next);
	}
	long long result = LLONG_MIN;
	for (int i = 0 ; i < n ; ++i) {
		result = max(result, dp[i]);
	}
	return result;
}
