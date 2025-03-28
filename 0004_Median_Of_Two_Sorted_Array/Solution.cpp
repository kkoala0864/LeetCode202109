#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;
using std::min;

double Solution::findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
	vector<int> &A = nums1.size() <= nums2.size() ? nums1 : nums2;
	vector<int> &B = nums1.size() <= nums2.size() ? nums2 : nums1;

	int m = A.size();
	int n = B.size();

	int half = (m + n + 1) >> 1;

	int l = 0, r = m;

	while (l <= r) {
		int i = l + ((r - l) >> 1);
		int j = half - i;

		int al = i > 0 ? A[i - 1] : INT_MIN;
		int ar = i < m ? A[i] : INT_MAX;

		int bl = j > 0 ? B[j - 1] : INT_MIN;
		int br = j < n ? B[j] : INT_MAX;

		if (al <= br && bl <= ar) {
			if ((m + n) & 1) {
				return max(al, bl);
			} else {
				double lm = max(al, bl);
				double rm = min(ar, br);
				return (lm + rm) / 2.0;
			}
		} else if (al > br) {
			r = i - 1;
		} else {
			l = i + 1;
		}
	}
	return -1;
}
