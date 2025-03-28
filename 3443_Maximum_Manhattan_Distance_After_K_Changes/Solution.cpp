#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;
using std::max;
using std::min;
using std::vector;

int Solution::maxDistance(string s, int k) {
	int hv = 0;
	int vv = 0;
	int hpc = 0;
	int vpc = 0;
	int hnc = 0;
	int vnc = 0;
	int result = 0;
	for (const auto &c : s) {
		if (c == 'E') {
			++hpc;
			++hv;
		} else if (c == 'W') {
			++hnc;
			--hv;
		} else if (c == 'S') {
			++vpc;
			++vv;
		} else {
			++vnc;
			--vv;
		}
		int opp = 0;
		opp += hv < 0 ? hpc : hnc;
		opp += vv < 0 ? vpc : vnc;
		int compensation = min(k, opp);
		result = max(result, abs(vv) + abs(hv) + (compensation * 2));
	}
	return result;
}
