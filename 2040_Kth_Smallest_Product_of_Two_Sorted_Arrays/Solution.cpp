#include <Solution.h>
#include <cmath>

long long getCnt(vector<int>& n1, vector<int>& n2, long long golden) {
	long long cnt = 0;
	for (const auto& v : n1) {
		if (v == 0) {
			// if golden < 0 then v * n2 == 0 should not be included
			cnt += (golden >= 0) ? (long long)n2.size() : 0;
		} else if (v > 0) {
			long long target = floor(golden * 1.0/(long long) v);
			long long idx = upper_bound(n2.begin(), n2.end(), target) - n2.begin();
			cnt += idx;
		} else {
			// 100 / -10 => -10, -9, -8...
			// -100 / -10 => 10, 11, 12...
			// so is v is negative, we need to include curIdx to the end
			long long target = ceil(golden * 1.0/ (long long) v);
			long long idx = lower_bound(n2.begin(), n2.end(), target) - n2.begin();
			cnt += ((long long)n2.size() - idx);
		}
	}
	return cnt;
}

long long Solution::kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
	vector<long long> n1 = {nums1[0], nums1.back()};
	vector<long long> n2 = {nums2[0], nums2.back()};
	long long l = LLONG_MAX;
	long long r = LLONG_MIN;
	for (const auto& v1 : n1) {
		for (const auto& v2 : n2) {
			l = min(l, v1 * v2);
			r = max(r, v1 * v2);
		}
	}

	long long mid = 0;

	while (l < r) {
		mid = l + ((r-l) >> 1);
		long long cnt = getCnt(nums1, nums2, mid);
		if (cnt >= k) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	return l;
}
