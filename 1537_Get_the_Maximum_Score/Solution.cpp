#include <Solution.h>

int Solution::maxSum(vector<int>& nums1, vector<int>& nums2) {
	int i1 = 0;
	int i2 = 0;
	long long p1 = 0;
	long long p2 = 0;
	long long result = 0;
	long long mod = 1e9 + 7;
	while (i1 < nums1.size() && i2 < nums2.size()) {
		if (nums1[i1] < nums2[i2]) {
			p1 += nums1[i1++];
		} else if (nums1[i1] > nums2[i2]) {
			p2 += nums2[i2++];
		} else {
			result += max(p1, p2);
			result %= mod;
			result += nums1[i1];
			result %= mod;
			p1 = 0;
			p2 = 0;
			++i1;
			++i2;
		}
	}
	while (i1 < nums1.size()) {
		p1 += nums1[i1++];
	}
	while (i2 < nums2.size()) {
		p2 += nums2[i2++];
	}
	result += max(p1, p2);
	result %= mod;
	return result;
}
