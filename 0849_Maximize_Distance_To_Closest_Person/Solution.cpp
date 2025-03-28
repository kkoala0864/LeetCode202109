#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

int Solution::maxDistToClosest(vector<int> &seats) {
	int result = 0;
	int start = 0;
	while (seats[start] == 0) {
		++start;
		++result;
	}
	int end = seats.size() - 1;
	while (seats[end] == 0)
		--end;
	result = max((int)(seats.size() - 1 - end), result);

	for (int i = start + 1; i < end; ++i) {
		int cnt = 0;
		while (i < end && seats[i] == 0) {
			++cnt;
			++i;
		}
		result = max(result, (cnt + 1) >> 1);
	}
	return result;
}
