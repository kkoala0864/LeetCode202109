#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::min;

int Solution::fixedPoint(vector<int>& arr) {
	int start = 0, end = arr.size() - 1;
	int mid = 0;
	int result = arr.size();
	while (start <= end) {
		mid = (end - start) / 2 + start;
		if (arr[mid] == mid) {
			result = min(result, mid);
			end = mid - 1;
		} else if (arr[mid] < mid) start = mid + 1;
		else end = mid - 1;
	}
	return result == arr.size() ? -1 : result;
}
