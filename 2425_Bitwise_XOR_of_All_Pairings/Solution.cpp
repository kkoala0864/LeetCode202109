#include <Solution.h>
#include <iostream>

int Solution::xorAllNums(vector<int>& nums1, vector<int>& nums2) {
	int result = 0;

	if (nums2.size() & 1) {
		for (const auto& v : nums1) {
			result = result ^ v;
		}
	}
	if (nums1.size() & 1) {
		for (const auto& v : nums2) {
			result = result ^ v;
		}
	}
	return result;
}
