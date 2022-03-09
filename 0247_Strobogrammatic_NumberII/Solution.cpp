#include <Solution.h>
#include <iostream>
vector<string> Solution::findStrobogrammatic(int n) {
	vector<vector<string>> dp;
	dp.push_back({"0","1","8"});
	dp.push_back({"11", "69", "88", "96"});
	if (n < 3) return dp[n-1];

	dp[1].push_back({"00"});
	for (int i = 2 ; i < n ; ++i) {
		vector<string> localV;
		for (const auto& core : dp[i-2]) {
			for (const auto& base : dp[1]) {
				if (i == n-1 && base[0] == '0') continue;
				string local(1, base[0]);
				local += core;
				local.push_back(base[1]);
				localV.emplace_back(local);
			}
		}
		dp.emplace_back(localV);
	}

	return dp[n-1];
}
