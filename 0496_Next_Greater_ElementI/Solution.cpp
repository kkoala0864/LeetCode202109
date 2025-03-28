#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

vector<int> Solution::nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
	vector<int> v(10001, -1);
	vector<int> result;

	for (int i = 0; i < nums2.size(); ++i) {
		v[nums2[i]] = i;
	}

	for (const auto &iter : nums1) {
		int i = v[iter] + 1;
		for (; i < nums2.size(); ++i) {
			if (nums2[i] > iter) {
				result.emplace_back(nums2[i]);
				break;
			}
		}
		if (i == nums2.size())
			result.emplace_back(-1);
	}
	return result;
}
