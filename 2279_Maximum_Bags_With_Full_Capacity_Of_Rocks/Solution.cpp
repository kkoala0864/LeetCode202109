#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;

int Solution::maximumBags(vector<int> &capacity, vector<int> &rocks, int additionalRocks) {
	vector<int> diff;
	int size = capacity.size();

	for (int i = 0; i < size; ++i) {
		diff.emplace_back(capacity[i] - rocks[i]);
	}

	sort(diff.begin(), diff.end());
	int result = 0;
	for (int i = 0; i < size && additionalRocks > 0; ++i) {
		if (additionalRocks >= diff[i]) {
			additionalRocks -= diff[i];
			++result;
		}
	}
	return result;
}
