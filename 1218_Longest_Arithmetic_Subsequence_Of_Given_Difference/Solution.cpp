#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::max;
using std::unordered_map;

int Solution::longestSubsequence(vector<int> &arr, int difference) {
	unordered_map<int, int> m;

	vector<int> dp(arr.size(), 1);

	int result = 0;
	for (int i = 0; i < arr.size(); ++i) {
		if (m.count(arr[i] - difference)) {
			dp[i] = m[arr[i] - difference] + 1;
		}
		m[arr[i]] = dp[i];
		result = max(result, dp[i]);
	}
	return result;
}
