#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

int Solution::getLastMoment(int n, vector<int> &left, vector<int> &right) {
	int result = 0;

	for (const auto &v : left) {
		result = max(result, v);
	}

	for (const auto &v : right) {
		result = max(result, n - v);
	}
	return result;
}
