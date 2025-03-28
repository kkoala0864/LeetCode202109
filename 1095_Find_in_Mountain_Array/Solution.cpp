#include <Solution.h>
#include <iostream>

int findPeak(MountainArray &mountainArr) {
	int l = 0, r = mountainArr.length() - 1;
	int mid = 0;

	while (l < r) {
		mid = l + ((r - l) >> 1);
		if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	return l;
}

int find(MountainArray &mountainArr, int target, int start, int end, bool isAscending) {
	int l = start, r = end;
	int mid = 0;

	while (l < r) {
		mid = l + ((r - l) >> 1);
		if (isAscending) {
			if (mountainArr.get(mid) < target) {
				l = mid + 1;
			} else {
				r = mid;
			}
		} else {
			if (mountainArr.get(mid) > target) {
				l = mid + 1;
			} else {
				r = mid;
			}
		}
	}
	return mountainArr.get(l) == target ? l : -1;
}

int Solution::findInMountainArray(int target, MountainArray &mountainArr) {

	int pi = findPeak(mountainArr);

	int lhs = find(mountainArr, target, 0, pi, true);
	int rhs = find(mountainArr, target, pi + 1, mountainArr.length() - 1, false);

	return lhs == -1 ? rhs : lhs;
}
