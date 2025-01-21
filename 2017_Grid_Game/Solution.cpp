#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::min;
using std::max;
using std::cout;
using std::endl;

long long Solution::gridGame(vector<vector<int>>& grid) {
	int size = grid[0].size();

	long long pre1 = 0;
	long long pre2 = 0;
	long long result = LLONG_MAX;
	for (int i = 0 ; i < size ; ++i) {
		pre1 += grid[0][i];
	}
	for (int i = 0 ; i < size; ++i) {
		pre1 -= grid[0][i];
		if (i > 0) {
			pre2 += grid[1][i-1];
		}
		long long v = max(pre1, pre2);
		result = min(result, v);
	}
	return result;
}
