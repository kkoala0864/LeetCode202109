#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

int Solution::getMaximumConsecutive(vector<int> &coins) {
	vector<int> map(40001, 0);

	int maxCoin = 0;
	for (const auto &iter : coins) {
		++map[iter];
		maxCoin = max(maxCoin, iter);
	}

	int maxCanReach = 0;
	for (int i = 1; i <= maxCoin; ++i) {
		if (map[i] == 0)
			continue;
		for (int j = 1; j <= map[i]; ++j) {
			if (maxCanReach >= ((i * j) - 1)) {
				maxCanReach += i;
			} else {
				return maxCanReach + 1;
			}
		}
	}
	return maxCanReach + 1;
}
