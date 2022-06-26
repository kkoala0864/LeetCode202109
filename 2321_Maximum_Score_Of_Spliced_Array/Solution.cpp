#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

int score(vector<int>& a, vector<int>& b) {
	int maxDiff = 0;
	int sum = 0;
	int diff = 0;
	for (int i = 0 ; i < a.size() ; ++i) {
		diff += (b[i] - a[i]);
		if (diff < 0) diff = 0;
		maxDiff = max(diff, maxDiff);
		sum += a[i];
	}
	return sum + maxDiff;
}

int Solution::maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
	return max(score(nums1, nums2), score(nums2, nums1));
}


