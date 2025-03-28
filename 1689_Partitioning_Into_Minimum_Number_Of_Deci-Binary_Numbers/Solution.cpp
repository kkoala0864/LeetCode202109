#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

int Solution::minPartitions(string n) {
	int result = 0;
	for (int i = 0; i < n.size(); ++i) {
		result = max(result, n[i] - '0');
	}
	return result == 0 ? 1 : result;
}
