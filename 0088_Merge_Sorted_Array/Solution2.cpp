#include <Solution.h>
#include <iostream>

void Solution::merge2(vector<int> &nums1, int m, vector<int> &nums2, int n) {
	int iter = m + n - 1;
	int i1 = m - 1;
	int i2 = n - 1;
	while (i1 >= 0 && i2 >= 0) {
		if (nums1[i1] > nums2[i2]) {
			nums1[iter--] = nums1[i1--];
		} else {
			nums1[iter--] = nums2[i2--];
		}
	}
	if (i2 >= 0) {
		while (i2 >= 0) {
			nums1[iter--] = nums2[i2--];
		}
	}
	return;
}
