#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

bool Solution::canPartition(vector<int> &nums) {
	int total = 0;
	for (const auto& v : nums) total += v;
	if (total & 1) return false;
	total = total >> 1;

	vector<int> dp(total + 1, false);
	vector<int> next = dp;
	next[0] = dp[0] = true;

	for (const auto& v : nums) {
		for (int i = v ; i <= total ; ++i) {
			if (dp[i - v]) {
				next[i] = true;
			}
		}
		dp = next;
		if (dp.back()) return true;
	}
	return false;
}
