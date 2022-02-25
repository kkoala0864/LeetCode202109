#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::min;
using std::max;

int Solution::hIndex2(vector<int>& citations) {
	int start = 0, end = citations.size() - 1;
	int mid = 0;
	int result = -1;
	int sz = citations.size();
	while (start <= end) {
		mid = (end - start) / 2 + start;
		result = max(result, min(sz - mid, citations[mid]));
		if (citations[mid] > (sz - mid)) {
			end = mid - 1;
		} else {
			start = mid + 1;
		}
	}
	return result;
}
