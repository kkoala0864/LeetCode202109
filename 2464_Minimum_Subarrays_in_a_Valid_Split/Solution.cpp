#include <Solution.h>

int getGCD(int a,int b) {
	if (a < b) swap(a,b);
	if (b == 0) return a;
	a %= b;
	return getGCD(b, a);
}

int Solution::validSubarraySplit(vector<int>& nums) {
	int size = nums.size();
	vector<int> dp(size + 1, INT_MAX);
	dp[0] = 0;

	for (int i = 0 ; i < size ; ++i) {
		for (int j = 0 ; j <= i ; ++j) {
			if (dp[j] == INT_MAX) continue;
			int g = getGCD(nums[i], nums[j]);
			if (g != 1) {
				dp[i+1] = min(dp[i+1], dp[j] + 1);
			}
		}
	}
	return dp.back() == INT_MAX ? -1 : dp.back();
}
