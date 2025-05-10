#include <Solution.h>

long long Solution::minSum(vector<int>& nums1, vector<int>& nums2) {
	long long s1 = 0, s2 = 0;
	long long c1 = 0, c2 = 0;
	for (const auto& v : nums1) {
		s1 += v;
		if (v == 0) ++c1;
	}
	for (const auto& v : nums2) {
		s2 += v;
		if (v == 0) ++c2;
	}
	if (c1 == 0 && c2 == 0) return s1 == s2 ? s1 : -1;
	if (c1 == 0) {
		if ((s2 + c2) > s1) return -1;
	}
	if (c2 == 0) {
		if ((s1 + c1) > s2) return -1;
	}

	long long min1 = s1 + c1;
	long long min2 = s2 + c2;
	return max(min1, min2);

}
