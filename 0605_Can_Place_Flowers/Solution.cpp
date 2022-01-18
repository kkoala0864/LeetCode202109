#include <Solution.h>
#include <iostream>

bool Solution::canPlaceFlowers(vector<int>& flowerbed, int n) {
	int start = 0;
	int end = flowerbed.size() - 1;
	int totalSize = 0;

	while (start < flowerbed.size() && flowerbed[start] == 0) ++start;
	totalSize += (start / 2);
	if (start == flowerbed.size()) return ((start + 1) / 2) >= n;

	while (end >= start && flowerbed[end] == 0) --end;
	totalSize += (flowerbed.size() - end - 1) / 2;

	for (int i = start+1 ; i <= end ; ++i) {
		int cnt = 0;
		while (i <= end && flowerbed[i] == 0) {
			++cnt;
			++i;
		}
		totalSize += (cnt-1) / 2;
	}
	return totalSize >= n;
}
