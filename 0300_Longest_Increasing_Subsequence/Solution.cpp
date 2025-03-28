#include <Solution.h>
#include <iostream>

using std::vector;

/*
int Solution::lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int maxLen = INT_MIN;

        for (int i = 1 ; i < nums.size() ; ++i) {
                for (int j = i ; j >= 0 ; --j) {
                        if (nums[i] > nums[j]) dp[i] = max(dp[i],  1 + dp[j]);
                }
        }

        for (const auto& iter : dp) maxLen = max(maxLen, iter);
        return maxLen;
}*/

int low_bound(const vector<int> &dp, int start, int end, int val) {
	while (start < end) {
		int mid = (end + start) / 2;
		if (dp[mid] > val)
			end = mid;
		else if (dp[mid] < val)
			start = mid + 1;
		else
			return mid;
	}
	return start;
}

int Solution::lengthOfLIS(vector<int> &nums) {
	if (nums.empty())
		return 0;
	vector<int> dp;
	dp.emplace_back(nums[0]);
	for (int i = 1; i < nums.size(); ++i) {
		int idx = low_bound(dp, 0, dp.size(), nums[i]);
		if (idx == dp.size())
			dp.emplace_back(nums[i]);
		else
			dp[idx] = nums[i];
	}
	return dp.size();
}
