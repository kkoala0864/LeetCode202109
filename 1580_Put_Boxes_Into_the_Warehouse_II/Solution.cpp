#include <Solution.h>

int Solution::maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
	sort(boxes.begin(), boxes.end());

	int maxb = boxes.back();
	int wSize = warehouse.size();
	vector<int> leftMin(wSize, maxb), rightMin(wSize, maxb);
	leftMin[0] = warehouse[0];
	rightMin.back() = warehouse.back();

	for (int i = 1 ; i < wSize ; ++i) {
		leftMin[i] = min(leftMin[i-1], warehouse[i]);
		rightMin[wSize-1-i] = min(rightMin[wSize - i], warehouse[wSize-1-i]);
	}

	for (int i = 0 ; i < wSize ; ++i) {
		warehouse[i] = max(leftMin[i], rightMin[i]);
	}
	sort(warehouse.begin(), warehouse.end());

	int result = 0;
	int wi = 0;
	for (int i = 0 ; i < boxes.size() ; ++i) {
		while (wi < wSize && warehouse[wi] < boxes[i]) {
			++wi;
		}
		if (wi == wSize) break;
		++result;
		++wi;
	}
	return result;
}
