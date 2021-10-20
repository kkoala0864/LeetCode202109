#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;
using std::min;
/*
int Solution::nthUglyNumber(int n) {
	vector<bool> dp = {false, true};
	vector<int> prime = {2,3,5};
	int cnt = 1;
	int iter = 2;
	while (cnt < n) {
		bool result = false;
		for (const auto& p : prime) {
			if ((iter % p) == 0) {
				int quo = iter / p;
				if (dp[quo]) {
					result = true;
					++cnt;
					break;
				}
			}
		}
		dp.push_back(result);
		++iter;
	}
	return dp.size()-1;
}
*/
int Solution::nthUglyNumber(int n) {
	vector<int> dp(n+1);
	dp[1]=1;
	int p2 = 1, p3 = 1, p5 = 1;

	for (int i = 2 ; i <= n ; ++i) {
		int v2 = 2 * dp[p2];
		int v3 = 3 * dp[p3];
		int v5 = 5 * dp[p5];
		int val = min({v2, v3, v5});
		dp[i] = val;
		if (val == v2) ++p2;
		if (val == v3) ++p3;
		if (val == v5) ++p5;
	}
	return dp[n];
}
