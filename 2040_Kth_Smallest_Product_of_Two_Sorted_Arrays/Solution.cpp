#include <Solution.h>
#include <iostream>
#include <cmath>

// n1 * n2 <= golden
// if n1 > 0 : n2 <= golden/n1;
// if n1 == 0 : golden > 0 ? n2.size() : 0;
// if n1 < 0 : n2 >= golden/n1;

long long getCnt(vector<int>& n1, vector<int>& n2, long long golden) {
	long long cnt = 0;
	for (const auto& v : n1) {
		if (v > 0) {
			long long target = floor(golden*1.0 / v);
			long long idx = upper_bound(n2.begin(), n2.end(), target) - n2.begin();
			cnt += idx;
		} else if (v == 0) {
			cnt += (golden >= 0) ? (long long)n2.size() : 0;
		} else {
			long long target = ceil(golden*1.0 / v);
			long long idx = lower_bound(n2.begin(), n2.end(), target) - n2.begin();
			cnt += ((long long)n2.size() - idx);
		}
	}
	return cnt;
}

long long Solution::kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
	long long l = min({(long long)nums1[0] * (long long)nums2[0],
			     (long long)nums1[0] * (long long)nums2.back(),
			     (long long)nums1.back() * (long long)nums2[0],
			     (long long)nums1.back() * (long long)nums2.back()});


	long long r = max({(long long)nums1[0] * (long long)nums2[0],
			     (long long)nums1[0] * (long long)nums2.back(),
			     (long long)nums1.back() * (long long)nums2[0],
			     (long long)nums1.back() * (long long)nums2.back()});


	long long mid = 0;
	while (l < r) {
		mid = l + ((r - l) >> 1);
		long long cnt = getCnt(nums1, nums2, mid);
		if (cnt < k) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	return l;
}
