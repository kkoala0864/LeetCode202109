#include <Solution.h>
#include <iostream>
#include <algorithm>

int Solution::maxCoins(vector<int>& piles) {
	sort(piles.begin(), piles.end(), std::greater<int>());

	int result = 0;
	int time = piles.size() / 3;
	for (int i = 0 ; i < time ; ++i) {
		result += piles[1 + i * 2];
	}
	return result;
}
