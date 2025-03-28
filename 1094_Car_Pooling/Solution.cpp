#include <Solution.h>
#include <iostream>
#include <algorithm>

bool Solution::carPooling(vector<vector<int>> &trips, int capacity) {
	vector<int> loc(1001, 0);
	int maxLoc = 0;
	int minLoc = 1001;
	for (const auto &iter : trips) {
		loc[iter[1]] += iter[0];
		loc[iter[2]] -= iter[0];
		if (iter[2] > maxLoc)
			maxLoc = iter[2];
		if (iter[1] < minLoc)
			minLoc = iter[1];
	}

	int seat = 0;
	for (int i = minLoc; i <= maxLoc; ++i) {
		seat += loc[i];
		if (seat > capacity)
			return false;
	}
	return true;
}
