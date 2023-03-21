#include <Solution.h>
#include <iostream>

bool Solution::canPlaceFlowers(vector<int>& flowerbed, int n) {
	int cnt = 0;
	for (int i = 0 ; i < flowerbed.size() ; ++i) {
		if (flowerbed[i] == 1) continue;

		if (i > 0) {
			if (flowerbed[i-1] == 1) continue;
		}
		if (i < flowerbed.size() - 1) {
			if (flowerbed[i+1] == 1) continue;
		}

		flowerbed[i] = 1;
		++cnt;
	}
	return cnt >= n;
}
