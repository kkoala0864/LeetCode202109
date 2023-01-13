#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

long long Solution::minimumHealth(vector<int>& damage, int armor) {
	long long result = 0;
	int maxVal = 0;

	for (const auto& d : damage) {
		maxVal = max(d, maxVal);
		result += d;
	}

	result -= (maxVal - armor > 0) ? armor : maxVal;
	return result + 1;
}
