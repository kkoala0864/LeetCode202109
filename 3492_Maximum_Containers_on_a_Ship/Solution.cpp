#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::min;

int Solution::maxContainers(int n, int w, int maxWeight) {
	int total = n * n;
	return min(maxWeight / w, total);
}
