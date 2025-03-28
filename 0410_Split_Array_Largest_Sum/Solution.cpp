#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::max;
using std::min;
/*
int dfs(vector<int>& nums, int m, int idx, vector<vector<int>>& dp) {
        if (dp[m][idx] != INT_MAX) return dp[m][idx];

        int sum = 0;
        if (m == 1) {
                for (int i = idx ; i < nums.size() ; ++i) sum += nums[i];
                dp[m][idx] = sum;
                return sum;
        }
        for (int i = idx ; i < nums.size()-m+1 ; ++i) {
                sum += nums[i];
                int local = dfs(nums, m - 1, i + 1, dp);
                dp[m][idx] = min(max(local, sum), dp[m][idx]);
                if (sum > dp[m][idx]) break;
        }
        return dp[m][idx];
}

int Solution::splitArray(vector<int>& nums, int m) {
        vector<vector<int>> dp(m + 1, vector<int>(nums.size(), INT_MAX));
        return dfs(nums, m, 0, dp);
}
*/
int minimumSubarraysRequired(vector<int> &nums, int maxSumAllowed) {
	int currentSum = 0;
	int splitsRequired = 0;

	for (int element : nums) {
		// Add element only if the sum doesn't exceed maxSumAllowed
		if (currentSum + element <= maxSumAllowed) {
			currentSum += element;
		} else {
			// If the element addition makes sum more than maxSumAllowed
			// Increment the splits required and reset sum
			currentSum = element;
			splitsRequired++;
		}
	}

	// Return the number of subarrays, which is the number of splits + 1
	return splitsRequired + 1;
}

int splitArray(vector<int> &nums, int m) {
	// Find the sum of all elements and the maximum element
	int sum = 0;
	int maxElement = INT_MIN;
	for (int element : nums) {
		sum += element;
		maxElement = max(maxElement, element);
	}

	// Define the left and right boundary of binary search
	int left = maxElement;
	int right = sum;
	int minimumLargestSplitSum = 0;
	while (left <= right) {
		int maxSumAllowed = left + (right - left) / 2;

		if (minimumSubarraysRequired(nums, maxSumAllowed) <= m) {
			right = maxSumAllowed - 1;
			minimumLargestSplitSum = maxSumAllowed;
		} else {
			left = maxSumAllowed + 1;
		}
	}

	return minimumLargestSplitSum;
}
