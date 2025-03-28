#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

int Solution::minimumAddedCoins(vector<int> &coins, int target) {
	sort(coins.begin(), coins.end());
	int result = 0;
	long m = 0;
	if (coins[0] != 1) {
		++result;
		m = 1;
	}
	for (const auto &c : coins) {
		while (m < (c - 1)) {
			m = max(m, m + m + 1);
			++result;
		}
		m += c;
	}
	while (m < target) {
		m = max(m, m + m + 1);
		++result;
	}

	return result;
}
