#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::min;

vector<int> Solution::intersect(vector<int> &nums1, vector<int> &nums2) {
	vector<int> result;

	vector<int> cnt1(1001, 0), cnt2(1001, 0);
	for (const auto &v : nums1)
		++cnt1[v];
	for (const auto &v : nums2)
		++cnt2[v];

	for (int i = 0; i < 1001; ++i) {
		if (cnt1[i] == 0 || cnt2[i] == 0)
			continue;
		int t = min(cnt1[i], cnt2[i]);
		for (int j = 0; j < t; ++j)
			result.emplace_back(i);
	}
	return result;
}
