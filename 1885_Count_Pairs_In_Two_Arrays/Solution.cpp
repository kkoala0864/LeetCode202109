#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;

long long Solution::countPairs(vector<int> &nums1, vector<int> &nums2) {
	vector<int> diff;
	for (int i = 0; i < nums1.size(); ++i) {
		diff.emplace_back(nums1[i] - nums2[i]);
	}

	sort(diff.begin(), diff.end());

	long long result = 0;
	int size = diff.size();
	for (int i = 0; i < size - 1; ++i) {
		int idx = upper_bound(diff.begin() + i + 1, diff.end(), -diff[i]) - diff.begin();
		if (idx == size)
			continue;
		result += (size - idx);
	}
	return result;
}
