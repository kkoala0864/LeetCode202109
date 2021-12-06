#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

int Solution::minCostToMoveChips(vector<int>& position) {
	unordered_map<int, int> uMap;
	int odd = 0;
	int even = 0;

	for (int i = 0 ; i < position.size() ; ++i) {
		if (position[i] & 1) ++odd;
		else ++even;
	}

	return odd > even ? even : odd;
}
