#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;
using std::min;

int Solution::nthUglyNumber2(int n) {
	vector<int> dp(n+1, 0);
	dp[1] = 1;
	int i2 = 1, i3 = 1, i5 = 1;

	for (int i = 2 ; i <= n ; ++i) {
		int v2 = 2 * dp[i2];
		int v3 = 3 * dp[i3];
		int v5 = 5 * dp[i5];
		int v = min({v2, v3, v5});
		dp[i] = v;
		if (v == v2) ++i2;
		if (v == v3) ++i3;
		if (v == v5) ++i5;
	}
	return dp[n];
}
