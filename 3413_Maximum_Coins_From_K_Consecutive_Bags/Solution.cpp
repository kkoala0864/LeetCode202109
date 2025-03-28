#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;
using std::sort;
using std::swap;

long long helper(vector<vector<int>> &coins, int k) {
	long long result = 0;
	long long sum = 0;
	int l = 0;
	for (int i = 0; i < coins.size(); ++i) {
		sum += ((long long)(coins[i][1] - coins[i][0] + 1) * (long long)coins[i][2]);
		int leftSide = coins[i][1] - k + 1;

		while (l < i && leftSide > coins[l][1]) {
			sum -= ((long long)(coins[l][1] - coins[l][0] + 1) * (long long)coins[l][2]);
			++l;
		}

		long long rest = 0;
		if (leftSide >= coins[l][0]) {
			rest = ((long long)(leftSide - coins[l][0]) * (long long)coins[l][2]);
		}
		result = max(sum - rest, result);
	}
	return result;
}

long long Solution::maximumCoins(vector<vector<int>> &coins, int k) {
	sort(coins.begin(), coins.end());

	long long result = 0;
	result = max(helper(coins, k), result);
	for (auto &c : coins) {
		swap(c[0], c[1]);
		c[0] *= -1;
		c[1] *= -1;
	}
	reverse(coins.begin(), coins.end());
	result = max(helper(coins, k), result);
	return result;
}
