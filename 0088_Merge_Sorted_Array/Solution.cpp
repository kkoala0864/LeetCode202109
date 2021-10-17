#include <Solution.h>
#include <iostream>

void Solution::merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	int idx1 = m - 1;
	int idx2 = n - 1;
	int k = m + n - 1;
	while (idx1 >= 0 && idx2 >= 0) {
		if (nums1[idx1] >= nums2[idx2]) {
			nums1[k--] = nums1[idx1--];
		} else {
			nums1[k--] = nums2[idx2--];
		}
	}
	if (idx2 > 0) {
		while (idx2 >= 0) {
			nums1[k--] = nums2[idx2--];
		}
	}
}
