#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;
using std::min;

bool Solution::isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
	int xdiff = abs(sx - fx);
	int ydiff = abs(sy - fy);
	int reduce = min(xdiff, ydiff);
	int rest = max(xdiff - reduce, ydiff - reduce);
	if ((reduce + rest == 0) && t == 1)
		return false;
	return (reduce + rest) <= t;
}
