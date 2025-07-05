#include <Solution.h>

int Solution::countBlocks(BigArray* nums) {

	long long size = nums->size();
	long long l = 0, r = size - 1;
	long long mid = 0;

	int result = 0;
	while (l < size) {
		while (l < r) {
			mid = r - ((r - l) >> 1);
			if (nums->at(mid) != nums->at(l)) {
				r = mid - 1;
			} else {
				l = mid;
			}
		}
		++result;
		++l;
		r = size - 1;
	}
	return result;
}

