#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;
using std::max;
using std::cout;
using std::endl;

long long Solution::maximumCoins(vector<vector<int>>& coins, int k) {
	coins.push_back({0,0,0});
	sort(coins.begin(), coins.end());

	long long result = 0;
	long long sum = 0;
	int l = 0;
	for (int i = 0 ; i < coins.size() ; ++i) {
		sum += ((long long)(coins[i][1] - coins[i][0] + 1) * (long long)coins[i][2]);
		int leftSide = coins[i][1] - k + 1;

		while (l < i && leftSide > coins[l][1]) {
			sum -= ((long long)(coins[l][1] - coins[l][0] + 1) * (long long) coins[l][2]);
			++l;
		}

		long long rest = 0;
		if (leftSide >= coins[l][0]) {
			rest = ((long long)(leftSide - coins[l][0]) * (long long)coins[l][2]);
		}
		result = max(sum - rest, result);
	}
	sum = 0;
	l = coins.size() - 1;
	for (int i = coins.size() - 1 ; i >= 0 ; --i) {
		sum += ((long long)(coins[i][1] - coins[i][0] + 1) * (long long)coins[i][2]);
		int rightSide = coins[i][0] + k - 1;

		while (i < l && rightSide < coins[l][0]) {
			sum -= ((long long)(coins[l][1] - coins[l][0] + 1) * (long long) coins[l][2]);
			--l;
		}
		long long rest = 0;
		if (rightSide <= coins[l][1]) {
			rest = ((long long)(coins[l][1] - rightSide) * (long long)coins[l][2]);
		}
		result = max(sum - rest, result);
	}
	return result;
}
