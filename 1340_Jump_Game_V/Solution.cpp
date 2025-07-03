#include <Solution.h>

int Solution::maxJumps(vector<int>& arr, int d) {
	int size = arr.size();
	vector<pair<int, int>> list;
	for (int i = 0 ; i < size ; ++i) {
		list.emplace_back(pair<int, int>(arr[i], i));
	}
	sort(list.begin(), list.end());
	vector<int> dp(size, INT_MIN);
	int result = 0;
	for (int i = 0 ; i < size ; ++i) {
		int curIdx = list[i].second;
		dp[curIdx] = 1;
		for (int i = curIdx - 1 ; i >= max(0, curIdx - d) ; --i) {
			if (arr[curIdx] <= arr[i]) break;
			dp[curIdx] = max(dp[curIdx], dp[i] + 1);
		}
		for (int i = curIdx + 1 ; i <= min(size-1, curIdx + d) ; ++i) {
			if (arr[curIdx] <= arr[i]) break;
			dp[curIdx] = max(dp[curIdx], dp[i] + 1);
		}
		result = max(result, dp[curIdx]);
	}
	return result;
}
