#include <Solution.h>
#include <iostream>

bool Solution::threeConsecutiveOdds(vector<int>& arr) {
	int cnt = 0;

	for (const auto& v : arr) {
		if (v & 1) ++cnt;
		else cnt = 0;
		if (cnt == 3) return true;
	}
	return false;
}

