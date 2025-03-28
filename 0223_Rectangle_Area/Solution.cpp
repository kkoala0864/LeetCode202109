#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;
using std::min;

int Solution::computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
	int x1 = max(ax1, bx1);
	int y1 = max(ay1, by1);
	int x2 = min(ax2, bx2);
	int y2 = min(ay2, by2);

	int result = ((ax2 - ax1) * (ay2 - ay1)) + ((bx2 - bx1) * (by2 - by1));
	if ((x2 - x1 > 0) && (y2 - y1 > 0)) {
		result -= ((x2 - x1) * (y2 - y1));
	}
	return result;
}
