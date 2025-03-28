#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

int Solution::sumSubarrayMins(vector<int> &arr) {
	int result = 0;
	int mod = 1e9 + 7;
	vector<int> dp(arr.size(), 0);
	vector<int> st;

	for (int i = 0; i < arr.size(); ++i) {
		while (!st.empty() && arr[st.back()] >= arr[i]) {
			st.pop_back();
		}
		if (st.empty()) {
			dp[i] += arr[i] * (i + 1);
		} else {
			dp[i] += arr[i] * (i - st.back());
			dp[i] += dp[st.back()];
			dp[i] %= mod;
		}
		result += dp[i];
		result %= mod;
		st.emplace_back(i);
	}
	return result;
}
