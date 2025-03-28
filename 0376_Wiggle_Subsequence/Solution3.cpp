#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

int Solution::wiggleMaxLength3(vector<int> &nums) {
	int n = nums.size();

	vector<int> diff;
	for (int i = 0; i < nums.size() - 1; ++i) {
		int d = nums[i + 1] - nums[i];
		if (d != 0)
			diff.emplace_back(d);
	}
	if (diff.empty())
		return 1;

	vector<int> dp(diff.size(), 0);
	dp[0] = 1;
	for (int i = 0; i < diff.size(); ++i) {
		for (int j = i - 1; j >= 0; --j) {
			int check = ((diff[i] ^ diff[j]) >> 31) & 1;
			if (check == 1) {
				dp[i] = max(dp[i], dp[j] + 1);
				break;
			} else
				dp[i] = dp[j];
		}
	}
	return dp.back() + 1;
}
