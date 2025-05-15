#include <Solution.h>

int Solution::maximumSum(vector<int>& arr) {
	vector<int> dp = {arr[0], (int)-1e4};

	int result = arr[0];
	for (int i = 1 ; i < arr.size() ; ++i) {
		dp[1] = max(dp[1] + arr[i], dp[0]);
		dp[0] = max(dp[0] + arr[i], arr[i]);
		result = max({result, dp[0], dp[1]});
	}

	return result;
}
