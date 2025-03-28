#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int Solution::peakIndexInMountainArray(vector<int> &arr) {
	int l = 0, r = arr.size() - 1;
	int mid = -1;

	while (l < r) {
		mid = l + ((r - l) >> 1);

		if (arr[mid] < arr[mid + 1]) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	return l;
}
