#include <Solution.h>

// [maxValue, minSum]
int Solution::mctFromLeafValues(vector<int>& arr) {
	int size = arr.size();
	vector<vector<pair<int, int>>> dp(size, vector<pair<int, int>>(size, pair<int, int>(INT_MIN, INT_MAX)));

	for (int i = 0 ; i < size ; ++i) {
		dp[i][i].first = arr[i];
		dp[i][i].second = 0;
	}

	for (int s = 2 ; s <= size ; ++s) {
		for (int i = 0 ; i <= size - s ; ++i) {
			for (int mid = i ; mid < (i + s - 1) ; ++mid) {
				dp[i][i+s-1].first = max({dp[i][i+s-1].first, dp[i][mid].first, dp[mid+1][i+s-1].first});
				dp[i][i+s-1].second = min(dp[i][i+s-1].second, dp[i][mid].second + dp[mid+1][i+s-1].second + (dp[i][mid].first * dp[mid+1][i+s-1].first));
			}
		}
	}
	return dp[0][size-1].second;
}
