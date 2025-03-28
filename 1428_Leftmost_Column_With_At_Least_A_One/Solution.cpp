#include <Solution.h>
#include <iostream>

int Solution::leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
	vector<int> dim = binaryMatrix.dimensions();
	int m = dim[0];
	int n = dim[1];

	int rx = m;
	int ry = n;

	for (int i = 0; i < m; ++i) {
		int l = 0, r = n - 1;
		int mid = 0;
		while (l < r) {
			mid = l + ((r - l) >> 1);
			if (binaryMatrix.get(i, mid) == 0) {
				l = mid + 1;
			} else {
				r = mid;
			}
		}
		if (binaryMatrix.get(i, l) == 1) {
			if (ry > l) {
				ry = l;
				rx = i;
			}
		}
	}
	return ry == n ? -1 : ry % n;
}
