#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

int Solution::sumSubarrayMins(vector<int>& arr) {
	int result = 0;
	int mod = 1e9 + 7;
	vector<int> dp(arr.size(), 0);
	vector<int> st;

	for (int i = 0 ; i < arr.size() ; ++i) {
		dp[i] += arr[i];
		dp[i] %= mod;
		while (!st.empty() && arr[st.back()] >= arr[i]) {
			int offset = st.back();
			st.pop_back();
			offset -= (st.empty() ? -1 : st.back());
			dp[i] += arr[i] * offset;
			dp[i] %= mod;
		}
		if (!st.empty()) {
			dp[i] += dp[st.back()];
			dp[i] %= mod;
		}
		result += dp[i];
		result %= mod;
		st.emplace_back(i);
	}
	return result;
}
