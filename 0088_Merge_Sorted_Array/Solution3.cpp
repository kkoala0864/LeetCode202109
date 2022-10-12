#include <Solution.h>
#include <iostream>

void Solution::merge3(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	int resultIdx = m + n - 1;
	int idx1 = m - 1, idx2 = n - 1;

	while (idx1 >= 0 || idx2 >= 0) {
		if (idx1 < 0) {
			nums1[resultIdx--] = nums2[idx2--];
		} else if (idx2 < 0) {
			nums1[resultIdx--] = nums1[idx1--];
		} else {
			nums1[resultIdx--] = nums1[idx1] > nums2[idx2] ? nums1[idx1--] : nums2[idx2--];
		}
	}
}
