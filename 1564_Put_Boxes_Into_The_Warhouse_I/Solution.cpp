#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::min;
using std::sort;

int Solution::maxBoxesInWarehouse(vector<int> &boxes, vector<int> &warehouse) {
	int minVal = INT_MAX;
	for (auto &w : warehouse) {
		minVal = min(minVal, w);
		w = minVal;
	}
	sort(boxes.begin(), boxes.end());
	int bi = 0, wi = warehouse.size() - 1;
	int result = 0;

	while (bi < boxes.size() && wi >= 0) {
		if (boxes[bi] <= warehouse[wi]) {
			++result;
			++bi;
		}
		--wi;
	}
	return result;
}
